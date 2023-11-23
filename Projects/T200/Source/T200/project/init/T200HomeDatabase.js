const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeDBSetup = require('../store/T200HomeDBSetup.js');
const T200Database = require('../../library/db/T200Database.js');
const T200DBClient = require('../../library/db/T200DBClient.js');

const T200HomeClear = require('./T200HomeClear.js');
const T200HomeCreate = require('./T200HomeCreate.js');


class T200HomeDatabase extends T200Database {
    constructor() {
        super();
        this.setup = new T200HomeDBSetup();
    }

    init() {
        log(__filename, "database init");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = false;
            return self.start().then(function(){
                log(__filename, "start success");
                let client = self.client();
                return client.connect().then(function(){
                    log(__filename, "connect success");

                    let HomeClear = new T200HomeClear();
                    return HomeClear.clear(client).then(function(){
                        log(__filename, "Home Clear success");
                    }, function(){
                        log(__filename, "Home Clear failure");
                        return error();
                    }).then(function(){
                        let HomeCreate = new T200HomeCreate();
                        return HomeCreate.create(client).then(function(){
                            log(__filename, "Home Create success");
                            result = true;
                        }, function(){
                            log(__filename, "Home Create failure");
                        });
                    }, function(){

                    }).finally(function(){
                        return client.disconnect().then(function(){
                            log(__filename, "disconnect success");
                        }, function(){
                            log(__filename, "disconnect failure");
                            result = false;
                            return error();
                        });
                    });
                }, function(){
                    log(__filename, "connect failure");
                }).finally(function(){
                    return self.stop().then(function(){
                        log(__filename, "stop success");
                    }, function(){
                        log(__filename, "stop failure");
                        result = false;
                    });
                });
            }, function(){
                log(__filename, "start failure");
            }).finally(function(){
                if(result){
                    resolve();
                }else{
                    reject();
                }
            });
        });

        return promise;
    }

}

log_start(__filename, "Home Database init");

let HomeDatabase = new T200HomeDatabase;

HomeDatabase.init().then(function(){
    log(__filename, "Home Database init success");
}, function(){
    log(__filename, "Home Database init failure");
});

log_stop(__filename, "Home Database init");