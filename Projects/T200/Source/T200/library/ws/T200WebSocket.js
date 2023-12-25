const T200WSFrame = require('./T200WSFrame.js');

const T200HttpsCookie = require('../net/T200HttpsCookie.js');
const T200HttpsSession = require('../net/T200HttpsSession.js');
const T200HttpsRequest = require('../net/T200HttpsRequest.js');
const T200HttpsForm = require('../net/T200HttpsForm.js');


class T200WebSocket {
    constructor(server) {
        this.#create(server);
    }

    #create(server) {
        let self = this;
        this._server = server;

        server.on('upgrade', function(req, res){
            self.upgrade(req, res);
        });
    }

    upgrade(req, res) {
        let self = this;

        let request = new T200HttpsRequest(req);
        let cookie = new T200HttpsCookie(req, res);

        cookie.load();

        let session = new T200HttpsSession(cookie);

        console.log('upgrade');

        let user_id = session.get("userid");
        let identity_id = session.get("identityid");

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_id(identity_id)){

            res.write(T200WSFrame.upgrade(req));
            res.id = identity_id;
            global.wsserver.append(identity_id, req, res);
    
            res.on('data', function(chunk){
                self.data(res, chunk);
            });
    
            res.on('end', function(){
                self.end();
            });
    
            res.on('error', function(){
                self.error();
            });
        }
    }

    data(res, chunk) {
        let self = this;
        console.log('data');
        let frame = T200WSFrame.parse(chunk);

        frame.source = res.id;

        switch(frame.opcode){
            case 1:
                self.command(res.id, frame.text);
                break;
            case 2:
                break;
            case 8:
                res.end();
                break;
        }
    }

    end() {
        console.log('end');
    }

    error() {
        console.log('error');
    }

    command(id, text) {
        let self = this;
        let cmd = JSON.parse(text);

        if(cmd){
            switch(cmd.command){
                case 'send':
                    self.send(id, cmd);
                    break;
            }
        }
    }

    send(id, cmd) {
        console.log(cmd.data);

        let obj = global.wsserver.get(cmd.id);

        if(obj){
            let frame = {};

            frame.command = "receive";
            frame.data = cmd.data;
            frame.id = id;

            let result = JSON.stringify(frame);

            let data = T200WSFrame.text(result);
            
            obj.res.write(data);
        }
    }

}

module.exports = T200WebSocket;