const T200Define = require('../T200Define.js');
const T200Module = require('./T200Module.js');

const T200Data = require('../data/T200Data.js');

const T200Text = require('./tags/T200Text.js');
const T200Email = require('./tags/T200Email.js');
const T200Button = require('./tags/T200Button.js');
const T200Password = require('./tags/T200Password.js');


class T200Form {
    constructor() {
        this.button_index = 0;

        this.tags = new Array();
        this.buttons = new Array();
        this.datas = new Array();
    }

    
    create(module) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            self.module = module;

            await self.#create_tags().then(function(){

            }, function(err){

            }).then(function(){
                return self.#create_buttons();
            }, function(err){

            }).then(function(){
                return self.#build_datas();
            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_tags() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let tag of self.module.define_value.fields){
                await self.#create_tag(tag).then(function(){

                }, function(err){
                    result = false;
                });

                if(!result)break;
            }

            if(result){
                resolve(self);
            }else{
                reject();
            }
        });

        return promise;
    }

    #create_tag(tag) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let value;
            switch(tag.type){
                case 'text':
                    value = new T200Text();
                    await self.#create_entry(tag, value).then(function(){
                        self.tags.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'password':
                    value = new T200Password();
    
                    await self.#create_entry(tag, value).then(function(){
                        self.tags.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'email':
                    value = new T200Email();
    
                    await self.#create_entry(tag, value).then(function(){
                        self.tags.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'button':
                    value = new T200Button();
    
                    await self.#create_entry(tag, value).then(function(){
                        self.buttons.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                default:
                    reject();
                    break;
            }
        });

        return promise;        
    }

    #create_entry(tag, value) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            value.project = self.project;
            value.page = self.page;
            await value.create(tag).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_buttons() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let tag of self.module.define_value.buttons){
                await self.#create_tag(tag).then(function(){

                }, function(err){
                    result = false;
                });

                if(!result)break;
            }

            if(result){
                resolve(self);
            }else{
                reject();
            }
        });

        return promise;
    }

    #find_button(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            for(let button of self.buttons){
                if(name == button.name){
                    resolve(button);
                    return;
                }
            }

            reject();
        });

        return promise;        
    }

    run(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            
        });

        return promise;
    }

    
    test_unit(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.browser = browser;
            let result = true;
            await self.#test_pass().then(function(){

            }, function(err){
                result = false;
            });

            if(result){
                await self.#test_error().then(function(){
                    result = false;
                }, function(err){
                    
                })
            }

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;        
    }

    #test_pass(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            //get
            //data
            //set data
            //click
            //wait
            //verify
            let result = true;

            do{
                await self.browser.get(self.browser.url(self.page)).then(function(){

                }, function(err){

                }).then(function(){
                    return self.#build_datas();
                }, function(err){

                }).then(function(){
                    return self.#set_datas();
                }, function(err){

                }).then(function(flag){
                    self.flag = flag;
                    return self.#click();
                }, function(err){

                }).then(function(){
                    return self.browser.sleep(1000);
                }, function(err){

                }).then(function(){
                    return self.browser.get_current_url();
                }, function(err){

                }).then(function(url){
                    let value = self.browser.url(self.module.define_value.value);
                    if(url == value){
                        return self.#verify();
                    }else{
                        result = false;
                    }
                }, function(err){

                }).then(function(){
                    
                }, function(err){
                    self.flag = false;
                    result = false;
                });
            }while(self.flag);

            if(result){                
                resolve();
            }else{
                self.#set_error();
                reject();
            }
        });

        return promise;
    }

    #set_error() {
        let self = this;

        for(let tag of self.tags){
            global.final.entry_failure(self.project, self.page, tag.field.name);
        }
        
    }

    #test_error(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            //get
            //data
            //set data
            //click
            //wait
            //verify
            reject();
        });

        return promise;        
    }

    #verify() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.browser.html().then(async function(html){
                await self.module.verify(html).then(function(){
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

    #set_datas() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let flag = false;

            for(let field of self.tags){
                if(undefined == field.index){
                    field.index = 0;
                }

                if(field.index < field.data.values.length - 1){
                    flag = true;
                    let value = field.data.values[field.index];
                    await field.run(self.browser, value).then(function(){
                        if(field.index < field.data.values.length - 1){
                            field.index++;
                        }
                    }, function(err){
                        result = false;
                    });
                }else{
                    
                }
            }
            
            if(result){
                resolve(flag);
            }else{
                reject();
            }
        });

        return promise;       
    }

    #click() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.#find_button(self.submit).then(async function(button){
                if(button){
                    await button.run(self.browser).then(function(){
                        resolve();
                    }, function(err){
                        reject();
                    })
                }else{
                    reject();
                }
            }, function(err){
                reject();
            });                
        });

        return promise;        
    }

    #build_datas() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let field of self.module.define_value.fields){
                await self.#build_data(field).then(function(value){
                    self.datas.push(value);
                }, function(){
                    result = false;
                });

                if(!result)break;
            }       
            
            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;         
    }

    #build_data(data) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            resolve();
        });

        return promise;        
    }
}

module.exports = T200Form;