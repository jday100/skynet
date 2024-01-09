const T200Text = require('./elements/T200Text.js');
const T200Email = require('./elements/T200Email.js');
const T200Button = require('./elements/T200Button.js');
const T200Password = require('./elements/T200Password.js');


class T200Form {
    constructor() {
        this.button_index = 0;

        this.field_values = new Array();
        this.button_values = new Array();
        this.data_values = new Array();
    }

    create(module) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.name = module.name;
            self.type = module.type;
            self.value = module.value;
            self.submit = module.submit;
            self.fields = module.fields;
            self.buttons = module.buttons;         

            let result = true;

            if(undefined == module.data){

            }else{
                await self.#create_datas(module.data).then(function(){

                }, function(){
                    result = false;
                });
                
               self.data_values = module.data;
            }            

            if(result){
                for(let field of self.fields){
                    await self.#create_element(field).then(function(){
                        
                    }, function(err){
                        result = false;
                    });
    
                    if(!result)break;
                }
            }            

            if(result){
                for(let button of self.buttons){
                    await self.#create_element(button).then(function(){
                        
                    }, function(err){
                        result = false;
                    });
    
                    if(!result)break;
                }
            }

            if(result){
                resolve(self);
            }else{
                reject();
            }
        });

        return promise;
    }

    #create_element(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let obj;
            switch(element.type){
                case 'text':
                    obj = new T200Text();
    
                    obj.create(element).then(function(){
                        self.field_values.push(obj);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'password':
                    obj = new T200Password();
    
                    obj.create(element).then(function(){
                        self.field_values.push(obj);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'email':
                    obj = new T200Email();
    
                    obj.create(element).then(function(){
                        self.field_values.push(obj);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'button':
                    obj = new T200Button();
    
                    obj.create(element).then(function(){
                        self.button_values.push(obj);
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

    #create_datas(datas) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let data of datas){
                await self.#create_data(data).then(function(obj){
                    self.data_values.push(obj);
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

    #create_data(data) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            resolve();
        });

        return promise;        
    }

    #create_button(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let obj = new T200Button();
    
            obj.create(element).then(function(){
                self.button_values.push(obj);
                resolve();
            }, function(err){
                reject();
            });
          
        });

        return promise;        
    }

    
    run1(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let field of self.field_values){
                await field.run(browser).then(function(){

                }, function(err){
                    result = false;
                });
            }

            if(self.button_index >= self.buttons.length){
                result = false;
            }else{
                let button = self.button_values[self.button_index++];

                if(button){
                    await button.run(browser).then(function(){

                    }, function(err){
                        result = false;
                    });
                }else{
                    result = false;
                }
            }

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }

    run(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let data of self.data_values){
                for(let field of self.field_values){
                    let value = data[field.name];
                    await field.run(browser, value).then(function(){
    
                    }, function(err){
                        result = false;
                    });
                }

                if(result){
                    await self.#find_button(self.submit).then(async function(button){
                        if(button){
                            await button.run(browser).then(function(){
        
                            }, function(err){
                                result = false;
                            }).then(function(){
                                return browser.get_current_url();
                            }, function(err){
                                result = false;
                            }).then(function(url){
                                let result = `${browser.root}${self.value}`;
                                if(result == url){
                                    resolve();
                                }else{
                                    console.log(`${self.name} ${result}`);
                                    reject();
                                }
                            }, function(err){
                                result = false;
                            });
                        }else{
                            result = false;
                        }
                    }, function(err){

                    });
                }
 
                if(result){
                    resolve();
                }else{
                    reject();
                }
            }
        });

        return promise;
    }

    #find_button(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            for(let button of self.button_values){
                if(name == button.name){
                    resolve(button);
                    return;
                }
            }

            reject();
        });

        return promise;        
    }
}

module.exports = T200Form;