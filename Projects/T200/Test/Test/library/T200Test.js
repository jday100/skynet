const T200Setup = require('../project/T200Setup');
const T200Actuator = require('./T200Actuator.js');
const T200DBLoader = require('./T200DBLoader.js');
const T200WebLoader = require('./T200WebLoader.js');


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

    flow() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            await self.#start().then(async function(){
                let act = new T200Actuator();
                await act.test_flow().then(function(){
                    
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
            let db = new T200DBLoader();
            await db.start().then(async function(){
                let web = new T200WebLoader();
                await web.start().then(function(){
                    resolve();
                }, function(err){
                    reject();
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
            let db = new T200DBLoader();
            await db.start().then(async function(){
                let web = new T200WebLoader();
                await web.start().then(function(){
                    
                }, function(err){

                });
            }, function(err){

            });
        });

        return promise;
    }
}

module.exports = T200Test;