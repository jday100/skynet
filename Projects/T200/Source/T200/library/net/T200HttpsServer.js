const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const http = require('http');
const formidable = require('formidable');

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
                let dispatcher = new T200HttpsDispatcher();

                let request = new T200HttpsRequest(req);
                let response = new T200HttpsResponse(res);
                let cookie = new T200HttpsCookie(req, res);

                cookie.load();

                let session = new T200HttpsSession(cookie);

                dispatcher.resource = self.resource;
                dispatcher.request = request;
                dispatcher.response = response;
                dispatcher.cookie = cookie;
                dispatcher.session = session;
                
                if(session.empty()){
                    request.on("load", function(){
                        self.distribute(dispatcher);
                    });

                    request.load();
                }else{
                    let user_id = session.get("userid");

                    if(user_id && 0 < user_id){
                        let form = new formidable.IncomingForm();

                        self.resource.merge_storages(user_id).then(function(data){
                            form.uploadDir = data;
                            //form.keepExtensions = true;
        
                            form.parse(req, function(err, fields, files){
                                if(err){
                                    response.error();
                                }else{
                                    request.fields = fields;
                                    request.files = files;
                                    self.distribute(dispatcher);
                                }
                            });
                        }, function(){
                            response.error();
                        });
                        
                    }else{
                        response.error();
                    }                    
                }

            });

            server.on('listen', function(){
                log(__filename, "Https Server listen success");
            });
            server.listen(8888);
        });

        return promise;
    }

    distribute(dispatcher) {
        log(__filename, "distribute");
        let self = this;

        dispatcher.run().then(function(data){
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
    }

}

module.exports = T200HttpsServer;