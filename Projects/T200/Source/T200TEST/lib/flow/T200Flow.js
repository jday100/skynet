const T200Resource = require('../T200Resource.js');
const T200Define = require('../T200Define.js');


class T200Flow {
    constructor(type) {
        this.type = type;
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.#create_define().then(function(){
                return self.#create_parser();
            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            })
        });

        return promise;
    }

    #create_define() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = T200Resource.merge_flow_define(self.type);

            if(file){
                T200Define.create(file).then(function(obj){
                    self.object = obj;
                    resolve(obj);
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }

    #create_parser() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = T200Resource.merge_flow_parser(self.type);

            if(file){
                let WebClass = require(file);

                if(WebClass){
                    let WebObj = new WebClass(self.object);
    
                    if(WebObj){
                        WebObj.create().then(function(){
                            self.parser = WebObj;
                            resolve(WebObj);
                        }, function(err){
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

    execute(browser, element) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            if(self.object && self.object.steps){
                for(let step of self.object.steps){
                    await self.parser.parse(browser, element, step).then(function(){

                    }, function(err){
                        result = false;
                    });
                }
            }else{
                result = false;
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

module.exports = T200Flow;