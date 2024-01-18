const T200Source = require('../T200Source.js');


class T200Web {
    constructor() {

    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            resolve();
        });

        return promise;
    }

    test_flow(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let html of self.html){
                await T200Source.create_web(self.project, html).then(async function(obj){
                    await obj.test_flow(browser).then(function(){
    
                    }, function(err){
                        result = false;
                    }).finally(function(){
           
                    });
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
    
    test_unit(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let html of self.html){
                await T200Source.create_web(self.project, html).then(async function(obj){
                    await obj.test_unit(browser).then(function(){
    
                    }, function(err){
                        result = false;
                    }).finally(function(){
           
                    });
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
}

module.exports = T200Web;