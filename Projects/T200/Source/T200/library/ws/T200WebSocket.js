const T200WSFrame = require('./T200WSFrame.js');


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

        console.log('upgrade');

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

    data(res, chunk) {
        let self = this;
        console.log('data');
        let frame = T200WSFrame.parse(chunk);

        switch(frame.opcode){
            case 1:
                self.command(frame.text);
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

    command(text) {
        let self = this;
        let cmd = JSON.parse(text);

        if(cmd){
            switch(cmd.command){
                case 'send':
                    self.send(cmd);
                    break;
            }
        }
    }

    send(cmd) {
        console.log(cmd.data);
    }

}

module.exports = T200WebSocket;