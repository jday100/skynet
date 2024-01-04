const T200Setup = require('../project/T200Setup.js');
const T200Object = require('./T200Object.js');
const T200Resource = require('./T200Resource.js');


class T200Source {
    constructor(name) {
        this.name = name;
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = T200Resource.merge_case(self.name);

            if(undefined == file){
                reject();
            }else{
                const CaseClass = require(file);

                if(undefined == CaseClass){
                    reject();
                }else{
                    let obj = new CaseClass();
    
                    if(undefined == obj){
                        reject();
                    }else{
                        obj.create().then(function(){
                            self.object = obj;
                            let methods = T200Object.methods(obj);
        
                            resolve(methods);
                        }, function(err){
                            reject();
                        });                        
                    }
                }
            }            
        });

        return promise;
    }

    run(browser, method) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.object[method](browser);
        });

        return promise;
    }
}

module.exports = T200Source;