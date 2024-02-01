const T200Error = require('../library/T200Error.js');
const { error, log, log_start, log_stop } = require('../library/T200Lib.js');

const http = require('http');

const T200HttpsSetup = require('../library/net/T200HttpsSetup.js');

const T200WSServer = require('../library/ws/T200WSServer.js');

const T200HttpsAction = require('../library/net/T200HttpsAction.js');
const T200HttpsCookie = require('../library/net/T200HttpsCookie.js');
const T200HttpsSession = require('../library/net/T200HttpsSession.js');
const T200HttpsRequest = require('../library/net/T200HttpsRequest.js');
const T200HttpsResponse = require('../library/net/T200HttpsResponse.js');
const T200HttpsResource = require('../library/net/T200HttpsResource.js');
const T200HttpsDispatcher = require('../library/net/T200HttpsDispatcher.js');

const T200HttpsServer = require('../library/net/T200HttpsServer.js');

const T200HomeSetup = require('./T200HomeSetup.js');
const T200HomeDBSetup = require('./store/T200HomeDBSetup.js');
const T200Database = require('../library/db/T200Database.js');
const T200HomeStore = require('./store/T200HomeStore.js');
const T200Setting = require('./models/T200Setting.js');


//const process = require('child_process');


class T200HomeServer extends T200HttpsServer {
    constructor() {
        super();
        global.setup.https = new T200HomeSetup();
        global.setup.database = new T200HomeDBSetup();
    }

    start() {
        log(__filename, "start");
        let self = this;

        process.on("SIGINT", function(){
            self.stop();
        });

        process.on("SIGTERM", function(){
            self.stop();
        });

        global.action = new T200HttpsAction();
        global.wsserver = new T200WSServer();
        this.resource = new T200HttpsResource();

        let promise = new Promise(function(resolve, reject){
            self.load().then(function(){

                //process.emit('SIGINT');
                self.run().then(function(){
                    //process.emit('SIGINT');
                    resolve();
                }, function(){
                    reject();
                });
            }, function(err){
                if(reject)reject(err);
            });
        });

        return promise;
    }

    stop() {
        console.log('stop');

        global.server.close();
        global.database.stop();
    }


    load() {
        log(__filename, "load");

        let self = this;
        let promise = new Promise(function(resolve, reject){
            Promise.all( [self.load_db(), self.load_app()] ).then(resolve, reject);
        });

        return promise;
    }

    load_db() {
        log(__filename, "load_db");

        let self = this;
        let promise = new Promise(function(resolve, reject){
            var database = new T200Database();

            database.setup = new T200HomeDBSetup();

            database.start().then(async function(){
                global.database = database;
                await self.load_setting().then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }, function(err){
                if(reject)reject(err);
            });
        });

        return promise;
    }

    load_setting() {
        log(__filename, "load_setting");

        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let store = new T200HomeStore();
            let setting = new T200Setting();

            setting.setting_id = '1000000';
            setting.flash_fields();
            await store.select(setting.merge_select_by_field("setting_id")).then(function(value){
                if(value){
                    if(1 == value.length){
                        let item = value[0];

                        if(item){
                            let content = item.content;

                            if(content){
                                let result = JSON.parse(content);

                                if(result){
                                    global.setup.server = result;
                                    resolve();
                                }else{
                                    reject();
                                }

                            }else{
                                reject();
                            }
                        }else{
                            reject();
                        }
                    }else{
                        resolve();
                    }
                }else{
                    reject();
                }
            }, function(err){
                reject();
            });
            
        });

        return promise;
    }

    load_app() {
        log(__filename, "load_app");

        let self = this;
        let promise = new Promise(function(resolve, reject){
            let name = self.resource.merge_app();

            self.resource.exists(name).then(function(){
                let result = self.resource.load_action(name);
                if(result){
                    if(resolve)resolve();
                }else{
                    if(reject)reject("load action error");
                };
            }, function(err){
                if(reject)reject(err);
            });
        });

        return promise;
    }
}

module.exports = T200HomeServer;