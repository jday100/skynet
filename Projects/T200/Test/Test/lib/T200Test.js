const child = require('child_process');

const T200Data = require('./T200Data.js');
const T200Source = require('./T200Source.js');
const T200Browser = require('./T200Browser.js');
const T200Resource = require('./T200Resource.js');
const T200Final = require('./report/T200Final.js');
const T200Report = require('./report/T200Report.js');


const T200Setup = require('../project/T200Setup.js');
const { error } = require(T200Setup.external('./library/T200Lib.js'));
const T200Database = require(T200Setup.external('./library/db/T200Database.js'));
const T200DBSetup = require('../project/T200DBSetup.js');


class T200Test {
    constructor() {

    }

    run(browser, source, method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            await self.#start().then(async function(){
                await self.#start_test(browser).then(async function(){
                    await self.#run_test(source, method).then(function(){

                    }, function(err){
                        result = false;
                    }).finally(async function(){
                        await self.#stop_test().then(function(){

                        }, function(err){
                            result = false;
                        });
                    })                    
                }, function(err){
                    result = false;
                }).finally(async function(){
                    await self.#stop().then(function(){

                    }, function(err){
                        result = false;
                    });
                });                
            }, function(err){
                result = false;
            });

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }

    test(browser, source, method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            await self.#start().then(async function(){
                await self.#start_test(browser).then(async function(){
                    await self.#exec_test(source, method).then(function(){

                    }, function(err){
                        result = false;
                    }).finally(async function(){
                        await self.#stop_test().then(function(){

                        }, function(err){
                            result = false;
                        });
                    })                    
                }, function(err){
                    result = false;
                }).finally(async function(){
                    await self.#stop().then(function(){

                    }, function(err){
                        result = false;
                    });
                });                
            }, function(err){
                result = false;
            });

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
            global.final = new T200Final();
            self.#start_db().then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.#start_web();
            }, function(err){
                return error();
            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #stop() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            await self.#stop_web().then(function(){

            }, function(err){
                result = false;
            }).finally(function(){
                return self.#stop_db();
            }).then(function(){

            }, function(err){
                result = false;
            });

            if(result){
                resolve();
            }else{
                reject();
            }
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
            let result = self.server.kill('SIGTERM');

            self.server.emit('SIGINT');
            self.server.emit('SIGTERM');

            process.emit('SIGINT');
            process.emit('SIGTERM');
            resolve();
        });

        return promise;
    }

    #start_db() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            setTimeout(async function(){
                let database = new T200Database();
                database.setup = new T200DBSetup();

                database.start().then(function(){
                    global.database = database;
                    resolve();
                }, function(err){
                    reject();
                });
            });            
        });

        return promise;
    }

    #stop_db() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(global.database){
                global.database.stop().then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    #start_test(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            global.final.append_project(T200Setup.name);
            T200Browser.create(browser).then(async function(browsers){
                self.browsers = browsers;
                await self.#load_data().then(resolve, reject);
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #load_data() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let data = new T200Data();

            await data.create().then(function(){
                self.data = data;
                resolve();
            }, function(err){
                reject();
            })
        });

        return promise;
    }

    #stop_test() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let browser of self.browsers){
                await browser.close().then(function(){

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

    #run_test(source, method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let browser of self.browsers){
                if(undefined == source){
                    await self.#search(browser).then(resolve, reject);
                }else{
                    if(source.endsWith('/')){
                        await self.#search_test(browser, source, method).then(resolve, reject);
                    }else{
                        await self.#execute(browser, source, method).then(resolve, reject);
                    }                    
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
                    obj.project = T200Setup.name;
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

    #search_test(browser, source, method) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = T200Resource.merge_test_case(source);

            if(file){
                T200Source.create(file).then(function(obj){
                    T200Source.test(browser, obj).then(function(){
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

    #exec_test(source, method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let browser of self.browsers){
                if(undefined == source){
                    reject();
                    return;
                }else{
                    await self.#execute(browser, source, method).then(resolve, reject);
                }
            }
            
        });

        return promise;
    }

    #execute(browser, source, method) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = T200Resource.merge_test_unit(source);

            if(file){
                T200Source.create(file).then(function(obj){
                    T200Source.test(browser, obj).then(function(){
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

    report() {
        let result = new T200Report();

        result.report();
    }
}

module.exports = T200Test;