const T200Define = require('../core/T200Define.js');
const T200Source = require('../core/T200Source.js');


class T200Page {
    constructor(name) {
        this.name = name;

        this.define_values = new Array();
        this.module_values = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.#create_page().then(function(){

            }, function(err){

            }).then(function(){
                return self.#create_defines();
            }, function(err){

            }).then(function(){
                return self.#create_modules();
            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_page() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            global.final.append_page(self.project, self.name);
            resolve();
        });

        return promise;
    }

    #create_defines() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let name of self.defines){
                await T200Define.create_web_page(self.project, name).then(function(value){
                    self.define_values.push(value);
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

    #create_modules() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let name of self.modules){
                await T200Source.create_web_module(self, self.project, name).then(function(value){
                    self.module_values.push(value);
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
}

module.exports = T200Page;