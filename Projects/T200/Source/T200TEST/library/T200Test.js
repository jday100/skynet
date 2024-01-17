const T200Setup = require('../project/T200Setup');
const { error } = require(T200Setup.external('./library/T200Lib.js'));

const T200Actuator = require('./T200Actuator.js');
const T200DBLoader = require('./T200DBLoader.js');
const T200WebLoader = require('./T200WebLoader.js');

const T200Final = require('./report/T200Final.js');
const T200Report = require('./report/T200Report.js');


class T200Test {
    constructor() {

    }

    run() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.unit().then(function(){
                
            }, function(err){
                return error();
            }).then(function(){
                return self.flow();
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

    flow(category, project, type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            await self.#start().then(async function(){
                let act = new T200Actuator();
                await act.test_flow(category, project, type, source, method, subdir).then(function(){
                    
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

    unit(category, project, type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            await self.#start().then(async function(){
                let act = new T200Actuator();
                await act.test_unit(category, project, type, source, method, subdir).then(function(){
                    
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
        let promise = new Promise(async function(resolve, reject){
            global.final = new T200Final();
            self.database = new T200DBLoader();
            await self.database.start().then(async function(){
                self.server = new T200WebLoader();
                await self.server.start().then(function(){
                    resolve();
                }, async function(err){
                    await self.database.stop().then(async function(){
                        reject();
                    }, function(err){
                        reject();
                    });
                });
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
            await self.database.stop().then(async function(){
                
            }, function(err){
                result = false;
            });

            await self.server.stop().then(function(){
            
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

    report() {
        let result = new T200Report();

        result.report();
    }
}

module.exports = T200Test;