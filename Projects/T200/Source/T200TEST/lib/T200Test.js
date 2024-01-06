const T200Resource = require('./T200Resource.js');
const T200Browser = require('./T200Browser.js');
const T200Source = require('./T200Source.js');
const process = require('child_process');

const T200Setup = require('../project/T200Setup.js');
const T200Database = require(T200Setup.external('./library/db/T200Database.js'));

const T200DBSetup = require('../project/T200DBSetup.js');


class T200Test {
    constructor() {

    }

    run(browser, source, method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.#start().then(async function(){
                await self.#done(browser, source, method).then(resolve, reject).finally(async function(){
                    await self.#stop();
                });
            }, function(){

            })
            
        });

        return promise;
    }

    #done(browser, source, method) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.#create(browser).then(function(){
                if(undefined == source){
                    self.#search().then(resolve, reject);
                }else{
                    self.#execute().then(resolve, reject);
                }
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == browser){
                let browser = 'all';
                T200Browser.create(browser).then(function(browsers){
                    self.browsers = browsers;
                    resolve();
                }, function(err){
                    reject();
                });
            }else{
                T200Browser.create(browser).then(function(browsers){
                    self.browsers = browsers;
                    resolve();
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }

    #search() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let name = "test_case.js";
            let file = T200Resource.merge_test_case(name);

            if(file){
                let source = new T200Source(name);

                if(source){
                    source.create().then(function(){
                        self.#execute(source).then(resolve, reject);
                    }, function(err){
                        reject();
                    });
                }else{
                    reject();
                }
            }else{
                reject();
            }
        });

        return promise;
    }

    #execute(source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let browser of self.browsers){
                await source.run(browser, "test_case").then(function(){

                }, function(err){
                    result = false;
                });
            }

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }


    #start() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            setTimeout(function(){
                self.server = process.exec(`cd ../web/ && node ./T200Home.js`);

                global.database = new T200Database();
                global.database.setup = new T200DBSetup();

                global.database.start();
                resolve();
            });
        });

        return promise;
    }

    #stop() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.server){

            }else{
                self.server.kill();
                resolve();
            }
        });

        return promise;
    }
}

module.exports = T200Test;