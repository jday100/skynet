

const T200Text = require('./tags/T200Text.js');
const T200Email = require('./tags/T200Email.js');
const T200Select = require('./tags/T200Select.js');
const T200Button = require('./tags/T200Button.js');
const T200Password = require('./tags/T200Password.js');



class T200Form {
    constructor() {
        this.tags = new Array();
    }

    create(module){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            self.module = module;

            await self.#create_tags().then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_tags(){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let field of self.module.define_value.fields){
                await self.#create_tag(field).then(function(){

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

    #create_tag(field) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let value;
            field.data = self.data;
            switch(field.type){
                case 'timestamp':
                case 'integer':
                case 'string':
                case 'text':
                    value = new T200Text();
                    await self.#create_entry(field, value).then(function(){
                        self.tags.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'password':
                    value = new T200Password();
    
                    await self.#create_entry(field, value).then(function(){
                        self.tags.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'email':
                    value = new T200Email();
    
                    await self.#create_entry(field, value).then(function(){
                        self.tags.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'button':
                    value = new T200Button();
    
                    await self.#create_entry(field, value).then(function(){
                        self.buttons.push(value);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'select':
                    value = new T200Select();
    
                    await self.#create_entry(field, value).then(function(){
                        self.tags.push(value);
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
}

module.exports = T200Form;