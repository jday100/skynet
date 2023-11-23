const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const http = require('http');

const T200HttpsSetup = require('./T200HttpsSetup.js');

const T200HttpsAction = require('./T200HttpsAction.js');
const T200HttpsCookie = require('./T200HttpsCookie.js');
const T200HttpsSession = require('./T200HttpsSession.js');
const T200HttpsRequest = require('./T200HttpsRequest.js');
const T200HttpsResponse = require('./T200HttpsResponse.js');
const T200HttpsResource = require('./T200HttpsResource.js');
const T200HttpsDispatcher = require('./T200HttpsDispatcher.js');


class T200HttpsServer {
    constructor() {
        global.setup = {};
        global.setup.https = new T200HttpsSetup();
    }

    start() {
        log(__filename, "https server start");

        global.action = new T200HttpsAction();
        this.resource = new T200HttpsResource();

        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.run().then(resolve, reject);
        });

        return promise;
    }

    stop() {
        log(__filename, "https server stop");

        let self = this;
        let promise = new Promise(function(resolve, reject){

        });

        return promise;
    }

    run() {
        log(__filename, "https server run");

        let self = this;
        let promise = new Promise(function(resolve, reject){
            T200HttpsSession.clear();

            let server = http.createServer();

            server.on('request', function(req, res){

                self.distribute(req, res);

            });

            server.on('listen', function(){
                log(__filename, "Https Server listen success");
            });
            server.listen(8888);
        });

        return promise;
    }

    distribute(req, res) {
        log(__filename, "distribute");
        let self = this;
        let request = new T200HttpsRequest(req);

        request.on('load', function(){
            log(__filename, "request load");
            let dispatcher = new T200HttpsDispatcher();

            dispatcher.request = request;
            dispatcher.response = new T200HttpsResponse(res);
            dispatcher.resource = self.resource;
            dispatcher.cookie = new T200HttpsCookie(req, res);
            dispatcher.cookie.load();
            dispatcher.session = new T200HttpsSession(dispatcher.cookie);

            dispatcher.run(req, res).then(function(data){
                log(__filename, "dispatcher run success");
                dispatcher.response.success(data);
            }, function(err){
                log(__filename, "dispatcher run failure", err);
                dispatcher.response.failure();
            }).catch(function(err){
                log(__filename, "dispatcher run error");
                dispatcher.response.error();
            }).finally(function(){
                dispatcher.response.SEND_END();
            });

        });
        
    }

}

module.exports = T200HttpsServer;