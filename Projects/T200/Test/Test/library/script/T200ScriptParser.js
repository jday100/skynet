const T200Web = require('../web/T200Web.js');


class T200ScriptParser {
    constructor(script) {
        this.script = script;
    }

    run(method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let item = self.script[method];

            if(item){
                await self.#steps(item.flow).then(function(){
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
            
            switch(item.name){
                case 'get':
                    await self.#get(item).then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'form':
                    await self.#form(item).then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
            }

            if(result){
                resolve();
            }else{
                reject();
            }
        });
        
        return promise;
    }

    #get(item) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let web = new T200Web();

            await web.create(self.project, item.value).then(async function(){
                await web.run(self.browser).then(function(){
                    self.web = web;
                    resolve();
                }, function(err){
                    self.web = undefined;
                    reject();
                });
            }, function(err){
                self.web = undefined;
                reject();
            });
        });
        
        return promise;
    }

    #form(item) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == self.web){
                reject();
            }else{
                await self.web.form(self.browser).then(function(){
                    resolve();
                }, function(err){
                    reject();
                });       
            }            
        });
        
        return promise;
    }
}

module.exports = T200ScriptParser;