const T200Define = require('../core/T200Define.js');


const T200Form = require('./T200Form.js');

const T200Link = require('./tags/T200Link.js');
const T200Text = require('./tags/T200Text.js');
const T200Email = require('./tags/T200Email.js');
const T200Select = require('./tags/T200Select.js');
const T200Button = require('./tags/T200Button.js');
const T200Password = require('./tags/T200Password.js');


class T200Module {
    constructor() {
        this.values = new Array();
    }

    create(page) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.parent = page;
            await T200Define.create_web_module(self.project, self.name).then(function(value){
                self.define_value = value;
            }, function(err){

            }).then(function(value){
                return self.#create_module();
            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_module() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            switch(self.define_value.type){
                case undefined:
                    await self.#create_fields().then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'form':
                    await self.#create_form().then(function(){

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

    #create_fields() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let field of self.define_value.fields){
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
        });

        return promise;
    }

    #create_field(field) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let value;
            field.data = self.data;
            switch(field.type){
                case 'link':
                    value = new T200Link();
                    await self.#create_entry(field, value).then(function(){
                        self.values.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'text':
                    value = new T200Text();
                    await self.#create_entry(field, value).then(function(){
                        self.values.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'password':
                    value = new T200Password();
    
                    await self.#create_entry(field, value).then(function(){
                        self.values.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'email':
                    value = new T200Email();
    
                    await self.#create_entry(field, value).then(function(){
                        self.values.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'button':
                    value = new T200Button();
    
                    await self.#create_entry(field, value).then(function(){
                        self.values.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'select':
                    value = new T200Select();
    
                    await self.#create_entry(field, value).then(function(){
                        self.values.push(value);
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

    
    #create_entry(field, value) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            value.project = self.project;
            value.page = self.page;
            await value.create(field).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_form() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            let form = new T200Form();

            form.category = self.category;
            form.project = self.project;
            form.page = self.page;
            form.name = self.name;
            await form.create(self).then(function(){
                self.values.push(form);
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

module.exports = T200Module;