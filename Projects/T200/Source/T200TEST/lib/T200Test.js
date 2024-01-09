const child = require('child_process');

const T200Source = require('./T200Source.js');
const T200Browser = require('./T200Browser.js');
const T200Resource = require('./T200Resource.js');

const T200Setup = require('../project/T200Setup.js');
const T200Database = require(T200Setup.external('./library/db/T200Database.js'));
const T200DBSetup = require('../project/T200DBSetup.js');


class T200Test {
    constructor() {

    }

    run(browser, source, method) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.#start().then(function(){
                self.#start_test(browser).then(function(){
                    self.#run_test(source, method).then(function(){

                    }, function(){

                    }).finally(function(){
                        self.#stop().then(function(){

                        }, function(){
        
                        });
                    })                    
                }, function(){

                }).finally(function(){
                    self.#stop_test().then(function(){

                    }, function(err){
    
                    });
                });                
            }, function(){

            });
        });

        return promise;
    }

    #start() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.#start_db().then(function(){

            }, function(){

            }).then(function(){
                return self.#start_web();
            }, function(){

            }).then(function(){
                resolve();
            }, function(){

            });
        });

        return promise;
    }

    #stop() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.#stop_web().then(function(){

            }, function(){

            }).then(function(){
                return self.#stop_db();
            }, function(){

            }).then(function(){
                resolve();
            }, function(){

            });
        });

        return promise;
    }


    #start_web() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            setTimeout(function(){
                self.server = child.exec(`cd ../web/ && node ./T200Home.js`);
                resolve();
            });
        });

        return promise;
    }

    #stop_web() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = self.server.kill(SIGTERM);

            self.server.emit('SIGTERM');

            process.emit(SIGINT);
            resolve();
        });

        return promise;
    }

    #start_db() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            setTimeout(function(){
                let database = new T200Database();
                database.setup = new T200DBSetup();
    
                database.start();
                global.database = database;
                resolve();
            });            
        });

        return promise;
    }

    #stop_db() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(global.database){
                global.database.stop();
            }else{
                reject();
            }
        });

        return promise;
    }

    #start_test(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            T200Browser.create(browser).then(function(browsers){
                self.browsers = browsers;
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #stop_test() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            resolve();
        });

        return promise;
    }

    #run_test(source, method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let browser of self.browsers){
                if(undefined == source){
                    await self.#search(browser).then(resolve, reject);
                }else{
                    await self.#execute(browser, source, method).then(resolve, reject);
                }
            }
            
        });

        return promise;
    }

    #search(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let dir = "/";
            let file = T200Resource.merge_test_case(dir);

            if(file){
                T200Source.create(file).then(function(obj){
                    T200Source.run(browser, obj).then(function(){
                        resolve();
                    }, function(err){
                        reject();
                    });
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }

    #execute(source, method) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let dir = "/";
            let file = T200Resource.merge_test_case(dir);

            if(file){

            }else{
                T200Source.create(file).then(function(obj){
                    T200Source.run(obj).then(function(){
                        resolve();
                    }, function(){
                        reject();
                    });
                }, function(){

                });
            }
        });

        return promise;
    }
}

module.exports = T200Test;