const T200WSFrame = require('./T200WSFrame.js');

const T200HttpsCookie = require('../net/T200HttpsCookie.js');
const T200HttpsSession = require('../net/T200HttpsSession.js');
const T200HttpsRequest = require('../net/T200HttpsRequest.js');
const T200HttpsForm = require('../net/T200HttpsForm.js');

const T200HomeView = require('../../project/view/T200HomeView.js');
const T200UserFollow = require('../../project/models/T200UserFollow.js');
const T200HomeUserBiz = require('../../project/biz/T200HomeUserBiz.js');


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

        request.load();
        
        let cookie = new T200HttpsCookie(req, res);

        cookie.load();

        let session = new T200HttpsSession(cookie);

        console.log('upgrade');

        let user_id = session.get("userid");
        let identity_id = session.get("identityid");

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_id(identity_id)){

            let obj = {};

            obj.request = request;
            obj.cookie = cookie;
            obj.session = session;

            obj.req = req;
            obj.res = res;

            obj.user_id = user_id;
            obj.id = identity_id;
            res.id = identity_id;

            global.wsserver.append(obj);

            res.write(T200WSFrame.upgrade(req));
    
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
                case 'load':
                    self.load(id);
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

    load(id) {
        let self = this;
        let obj = global.wsserver.get(id);

        if(obj){
            let follow = new T200UserFollow();
            let UserBiz = new T200HomeUserBiz(obj.request, obj.cookie, obj.session);

            follow.user_id = obj.user_id;

            if(T200HttpsForm.verify_id(follow.user_id)){
                follow.flash_user_list_fields();
                UserBiz.list(follow.merge_user_list()).then(function(data){
                    self.list(id, data);
                }, function(err){
                    self.error(id);
                });
            }else{

            }
        }
    }

    list(id, data) {
        let self = this;
        let obj = global.wsserver.get(id);

        if(obj){
            let frame = {};

            frame.command = "list";
            frame.data = data;
            frame.id = id;

            let value = JSON.stringify(frame);

            let result = T200WSFrame.text(value);
            
            obj.res.write(result);
        }
        
    }


    error(id) {

    }

}

module.exports = T200WebSocket;