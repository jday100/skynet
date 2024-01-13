const T200Text = require('./elements/T200Text.js');
const T200Email = require('./elements/T200Email.js');
const T200Button = require('./elements/T200Button.js');
const T200Password = require('./elements/T200Password.js');
const T200Data = require('../T200Data.js');


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
                                let value = `${browser.root}${self.value}`;
                                if(value == url){
                                    //resolve();
                                }else{
                                    console.log(`${self.name} ${value}`);
                                    result = false;
                                    //reject();
                                }
                            }, function(err){
                                result = false;
                            });
                        }else{
                            result = false;
                        }
                    }, function(err){
                        result = false;
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

    test_case(browser) {
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

    #test_pass() {
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
                    let value = self.browser.url(self.value);
                    if(url == value){
                        
                    }else{
                        result = false;
                    }
                }, function(err){

                });
            }while(self.flag);

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;        
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

    
    #set_datas() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let flag = false;

            for(let field of self.field_values){
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
            resolve();
        });

        return promise;        
    }
}

module.exports = T200Form;