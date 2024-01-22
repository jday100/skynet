const T200Define = require('../core/T200Define.js');


const T200Form = require('./T200Form.js');


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
            let result = true;


            if(result){
                resolve();
            }else{
                reject();
            }
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