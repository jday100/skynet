const T200Web = require('../web/T200Web.js');


class T200ScriptParser {
    constructor(script) {
        this.script = script;
    }

    run(method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let flow = self.script[method];

            if(flow){
                await self.#steps(flow).then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });
        
        return promise;
    }

    #steps(flow) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let item of flow){
                await self.#step(item).then(function(){
                    
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

    #step(item) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            await self.#done(item).then(function(){
                    
            }, function(err){
                result = false;
            });
        });
        
        return promise;
    }

    #done(item) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let web = new T200Web();

            await web.create(self.project, item.name).then(async function(){
                await web.run(browser).then(function(){
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
}

module.exports = T200ScriptParser;