const T200Object = require('./T200Object.js');


class T200Source {
    constructor() {

    }

    static create(file) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let WebClass = require(file);

            if(WebClass){
                let WebObj = new WebClass();

                if(WebObj){
                    WebObj.create().then(function(){
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
        });

        return promise;
    }

    static run(browser, obj) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let methods = T200Object.run(obj);

            if(methods){
                for(let method of methods){
                    await obj[method](browser).then(function(){
                        
                    }, function(err){
                        reject();
                    });
                    if(!result)break;
                }
                if(result){
                    resolve();
                }else{
                    reject();
                }
            }else{
                reject();
            }
        });

        return promise;
    }
}

module.exports = T200Source;