const T200Define = require('../T200Define.js');
const T200Source = require('../T200Source.js');

const T200Form = require('./T200Form.js');
const T200Link = require('./tags/T200Link.js');


class T200Page {
    constructor(name) {
        this.name = name;
        
        this.tags = new Array();
        
        this.define_values = new Array();
        this.module_values = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.#create_defines().then(function(){

            }, function(err){

            }).then(async function(){
                return await self.#create_page();                
            }, function(err){

            }).then(async function(){
                return await self.#create_modules();
            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_defines() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let name of self.defines){
                await T200Define.create_web_page(name).then(function(value){
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

    #create_page() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            global.final.append_page(self.project, self.name);
            resolve();
        });

        return promise;
    }

    create_fields(module) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            switch(module.define_value.type){
                case undefined:
                    for(let field of module.define_value.fields){
                        await self.#create_field(field).then(function(){

                        }, function(err){
                            result = false;
                        });
                        if(!result)break;
                    }
                    
                    break;
                case 'form':
                    await self.#create_form(module).then(function(){

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

    #create_field(tag) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            tag.url = self.name;
            switch(tag.type){
                case 'link':
                    let value = new T200Link();
                    await self.#create_tag(tag, value).then(function(){
                        
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

    #create_tag(tag, value) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            value.project = self.project;
            value.page = self.name;
            await value.create(tag).then(function(){
                self.tags.push(value);
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_form(module) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let form = new T200Form();

            form.project = self.project;
            form.page = self.name;
            await form.create(module).then(function(){
                self.tags.push(form);
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    test_flow(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            await browser.sleep(500).then(function(){

            }, function(err){
                result = false;
            }).then(function(){
                return browser.sleep(500);
            }, function(err){
                result = false;
            }).then(async function(){
                for(let tag of self.tags){
                    await tag.test_unit(browser).then(function(){

                    }, function(err){
                        result = false;
                    });
                }
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
    
    test_unit(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            await browser.get(browser.url(self.name)).then(function(){

            }, function(err){
                result = false;
            }).then(function(){
                return browser.sleep(1000);
            }, function(err){
                result = false;
            }).then(async function(){
                for(let tag of self.tags){
                    await tag.test_unit(browser).then(function(){

                    }, function(err){
                        result = false;
                    });
                }
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
}

module.exports = T200Page;