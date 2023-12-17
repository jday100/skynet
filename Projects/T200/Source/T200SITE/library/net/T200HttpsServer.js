const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const http = require('http');

const T200FileDispatcher = require('./T200FileDispatcher.js');


class T200HttpsServer {
    constructor() {

    }

    start() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.run();
        });

        return promise;
    }

    stop() {
        let self = this;
        let promise = new Promise(function(resolve, reject){

        });

        return promise;
    }

    run() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let server = http.createServer();

            server.on('request', function(req, res){
                self.distribute(req, res);
            });

            server.on('listen', function(err){
                resolve();
            });

            server.listen(8888);
        });

        return promise;
    }

    distribute(req, res) {
        let dispatcher = new T200FileDispatcher();

        dispatcher.run(req, res);
    }
}

module.exports = T200HttpsServer;
