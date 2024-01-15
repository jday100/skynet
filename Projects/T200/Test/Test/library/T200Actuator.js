const T200Source = require('./T200Source.js');
const T200Browser = require('./web/T200Browser.js');


class T200Actuator {
    constructor() {

    }

    test_unit(category, project, type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            switch(category){
                case undefined:
                case 'all':
                    await self.#test_all(project, type, source, method, subdir).then(function(){

                    }, function(err){
    
                    });
                    break;
                case 'app':
                    await self.#test_app(project, type, source, method, subdir).then(function(){

                    }, function(err){
    
                    });
                    break;
                case 'web':
                    await self.#test_web(project, type, source, method, subdir).then(function(){
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
            }            
        });

        return promise;
    }

    test_flow() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    #test_all() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    #test_app() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    #test_web(project, type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            await self.#web_start(type).then(async function(){
                await self.#web_run(project, source, method, subdir).then(function(){

                }, function(err){
                    result = false;
                }).finally(async function(){
                    await self.#web_stop().then(function(){

                    }, function(err){
                        result = false;
                    });
                });
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

    #web_start(type) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){            
            await self.#create_web(type).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #web_stop() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == type){
                await self.#disp_web_all().then(function(){

                }, function(err){
                    
                });
            }else{

            }
        });

        return promise;
    }

    #create_web(type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Browser.create('firefox').then(function(browsers){
                self.browsers = browsers;
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #disp_web_all(type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == type){

            }else{

            }
        });

        return promise;
    }

    #web_run(project, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let browser of self.browsers){
                await self.#web_test(browser, project, source, method, subdir).then(function(){
        
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

    #web_test(browser, project, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == source){
                await self.#web_search();
            }else{
                if(source.endsWith('/')){
                    await self.#web_search(browser, project, source, method, subdir);
                }else{
                    await self.#web_done(browser, project, source, method);
                }
            }
        });

        return promise;
    }

    #web_search(browser, project, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == source){
                await self.#web_search();
            }else{
                if(source.endsWith('/')){
                    await self.#web_search(browser, source, method, subdir);
                }else{
                    await self.#web_done(browser, source, method);
                }
            }
        });

        return promise;
    }

    #web_done(browser, project, source, method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            T200Source.create_web(project, source).then(function(obj){
                obj.test_unit(browser).then(function(){

                }, function(err){

                }).finally(function(){
       
                });
            }, function(err){

            });
        });

        return promise;
    }


}

module.exports = T200Actuator;