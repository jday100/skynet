const T200Module = require('../../../../library/web/T200Module.js');


class T200HouseIndexModule extends T200Module {
    constructor() {
        super();
        this.name = "house/house_index";
    }

    run(browser, options){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let form = self.values[0];
            await form.run(browser, options).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    first(browser, options){
        let self = this;
        let promise = new Promise(async function(resolve, reject){     
            let result = true; 
            await browser.find(options.step.verify.locate).then(function(nodes){
                return nodes[0].getText();
            }, function(err){
                result = false;
            }).then(function(text){
                if(text == options.step.verify.success){

                }else{
                    result = false;
                }
            }, function(err){
                result = false;
            }).then(function(){
                if(result){
                    resolve();
                }else{
                    reject();
                }
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200HouseIndexModule;