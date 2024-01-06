const T200Link  = require('./elements/T200Link.js');
const T200Form  = require('./T200Form.js');


class T200Page {
    constructor() {
        this.elements = new Array();
    }

    create(web) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            self.web = web;

            for(let module of web.module_values){
                await self.#create_module(module).then(function(){

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

    #create_element(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            element.url = self.web.name;
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

    #create_module(module) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let obj of module.values){
                await self.#create_fields(obj).then(function(){

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

    #create_fields(module) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            if(undefined == module.type){
                for(let field of module.fields){
                    await self.#create_field(field).then(function(){
    
                    }, function(err){
                        result = false;
                    });
                    if(!result)break;
                }
            }else if("form" == module.type){
                await self.#create_form(module).then(function(){

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

    #create_field(field) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.#create_element(field).then(resolve, reject);
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
}

module.exports = T200Page;