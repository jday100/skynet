const T200Link  = require('./elements/T200Link.js');
const T200Form  = require('./T200Form.js');
const T200Source = require('../T200Source.js');
const T200Resource = require('../T200Resource.js');
const T200Store = require('../db/T200Store.js');


class T200Page {
    constructor(name) {
        this.name = name;
        this.elements = new Array();

        this.objects = new Array();
        this.modules = new Array();

        this.object_values = new Array();
        this.module_values = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let name of self.module_defines){
                await self.create_module(name).then(function(){
                    
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

    create_module(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let ModuleSource = T200Resource.merge_web_module(name);

            if(ModuleSource){
                const ModuleClass = require(ModuleSource);

                if(ModuleClass){
                    let ModuleObj = new ModuleClass(self);

                    if(ModuleObj){
                        ModuleObj.create().then(function(){
                            self.module_values.push(ModuleObj);
                            resolve();
                        }, function(){
                            reject();
                        });
                    }else{
                        reject();
                    }
                }else{
                    reject();
                }
            }else{
                reject();
            }
        });

        return promise;
    }

    #create_define(define) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            
        });

        return promise;
    }

    create_fields(obj) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            switch(obj.type){
                case undefined:
                    for(let field of obj.fields){
                        await self.#create_field(field).then(function(){

                        }, function(err){
                            result = false;
                        });
                        if(!result)break;
                    }
                    if(result){
                        resolve();
                    }else{
                        reject();
                    }
                    break;
                case 'form':
                    await self.#create_form(obj).then(function(){
                        resolve();
                    }, function(){
                        reject();
                    });
                    break;
            }
        });

        return promise;
    }

    #create_field(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            element.url = self.name;
            switch(element.type){
                case 'link':
                    let obj = new T200Link();
    
                    obj.create(element).then(function(){
                        self.elements.push(obj);
                        resolve();
                    }, function(){
                        reject();
                    });
                    break;
                case 'text':
                    break;
            }
        });

        return promise;  
    }

    
    #create_form(module) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let form = new T200Form();

            form.create(module).then(function(){
                self.elements.push(form);   
                resolve();  
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    create_store() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let store = new T200Store();

            await store.create().then(function(){
                self.store = store;
                resolve();
            }, function(){
                reject();
            });
        });

        return promise;
    }

    run(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let element of self.elements){
                await element.run(browser).then(function(){

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


    test_case1(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let element of self.elements){
                await element.run(browser).then(function(){

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

    test_case(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let element of self.elements){
                await element.run(browser).then(function(){

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