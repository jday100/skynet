const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Dotter = require('../../library/T200Dotter.js');

const T200HomeDBSetup = require('../store/T200HomeDBSetup.js');
const T200Database = require('../../library/db/T200Database.js');
const T200DBClient = require('../../library/db/T200DBClient.js');

const T200HomeClear = require('./T200HomeClear1.js');


class T200HomeDatabase extends T200Database {
    constructor() {
        super();
        this.setup = new T200HomeDBSetup();
    }

    init() {
        log(__filename, "home database init");
        this.dotter = new T200Dotter();

        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = false;
            self.dotter.hit(1);
            return self.start().then(function(){
                self.dotter.hit(2);
                return self.run().then(function(){
                    self.dotter.hit(15);
                    resolve();
                }, function(err){
                    self.dotter.hit(15);
                }).then(function(){
                    self.dotter.hit(16);
                }, function(){
                    self.dotter.hit(16);
                }).finally(function(){
                    self.dotter.hit(16);
                    return self.stop(function(){
                        self.dotter.hit(17);
                    }, function(err){
                        return error();
                    });
                });
            }, function(err){
                return error();
            });
        });

        return promise;
    }

    run() {
        log(__filename, "home database run");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = false;
            let client = self.client();

            self.dotter.hit(3);
            return client.connect().then(function(){
                self.dotter.hit(4);
                return self.clear(client).then(function(){
                    self.dotter.hit(10);
                }, function(err){
                    return error();
                }).then(function(){
                    self.dotter.hit(11);
                    return self.create(client);
                }, function(err){
                    return error();
                }).then(function(){
                    self.dotter.hit(12);
                }, function(err){

                });
                /*
                }).finally(function(){
                    self.dotter.hit(13);
                    / *
                    return client.disconnect().then(function(){
                        self.dotter.hit(14);
                    }, function(err){
                        return error();
                    });
                    * /
                });
                */
            }, function(err){

            }).then(function(){
                self.dotter.hit(14);
            }, function(){

            });
        });

        return promise; 
    }

    clear(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let HomeClear = new T200HomeClear();
            self.dotter.hit(5);
            HomeClear.dotter = self.dotter;
            return HomeClear.clear(client).then(function(){
                self.dotter.success(9);
                resolve();
            }, function(err){
                self.dotter.failure(10);
                reject();
            });

        });

        return promise;
    }

    create(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            resolve();

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
}).finally(function(){
    self.dotter.hit(18);
    if(HomeDatabase.dotter.judge()){
        log(__filename, "Result:", "true");
    }else{
        log(__filename, "Result:", "false");
    }
});


log_stop(__filename, "Home Database init");
