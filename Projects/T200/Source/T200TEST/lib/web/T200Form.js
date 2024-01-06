const T200Text = require('./elements/T200Text.js');
const T200Password = require('./elements/T200Password.js');
const T200Email = require('./elements/T200Email.js');
const T200Button = require('./elements/T200Button.js');


class T200Form {
    constructor() {
        this.elements = new Array();

        this.field_values = new Array();
        this.button_values = new Array();
    }

    create(module) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.name = module.name;
            self.type = module.type;
            self.fields = module.fields;
            self.buttons = module.buttons;
            

            let result = true;

            for(let field of self.fields){
                await self.#create_element(field).then(function(){
                    
                }, function(err){
                    result = false;
                });

                if(!result)break;
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
                        self.elements.push(obj);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'password':
                    obj = new T200Password();
    
                    obj.create(element).then(function(){
                        self.elements.push(obj);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'email':
                    obj = new T200Email();
    
                    obj.create(element).then(function(){
                        self.elements.push(obj);
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'button':
                    obj = new T200Button();
    
                    obj.create(element).then(function(){
                        self.elements.push(obj);
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

module.exports = T200Form;