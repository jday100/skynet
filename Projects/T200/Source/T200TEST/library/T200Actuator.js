const T200Source = require('./T200Source.js');
const T200Data = require('./data/T200Data.js');
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
                    await self.#test_unit_all(project, type, source, method, subdir).then(function(){
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'app':
                    await self.#test_unit_app(project, type, source, method, subdir).then(function(){
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'web':
                    await self.#test_unit_web(project, type, source, method, subdir).then(function(){
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
            }            
        });

        return promise;
    }

    test_flow(category, project, type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            global.data = new T200Data();
            switch(category){
                case undefined:
                case 'all':
                    await self.#test_flow_all(project, type, source, method, subdir).then(function(){
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'app':
                    await self.#test_flow_app(project, type, source, method, subdir).then(function(){
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
                case 'web':
                    await self.#test_flow_web(project, type, source, method, subdir).then(function(){
                        resolve();
                    }, function(err){
                        reject();
                    });
                    break;
            }            
        });

        return promise;
    }

    #test_flow_all() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    #test_flow_app() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    #test_flow_web(project, type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            await self.#web_start(type).then(async function(){
                await self.#web_flow_run(project, source, method, subdir).then(function(){

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

    #test_unit_all() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    #test_unit_app() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    #test_unit_web(project, type, source, method, subdir) {
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
            await self.#destroy_web_all().then(function(){
                resolve();
            }, function(err){
                reject();
            });            
        });

        return promise;
    }

    #create_web(type) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Browser.create(type).then(function(browsers){
                self.browsers = browsers;
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #destroy_web_all() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let browser of self.browsers){
                await browser.close();
            }

            if(result){
                resolve();
            }else{
                reject();
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
                await self.#web_search().then(resolve, reject);
            }else{
                if(source.endsWith('/')){
                    await self.#web_search(browser, project, source, method, subdir).then(resolve, reject);
                }else{
                    await self.#web_done(browser, project, source, method).then(resolve, reject);
                }
            }
        });

        return promise;
    }

    #web_search(browser, project, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == source){
                await self.#web_search().then(resolve, reject);
            }else{
                if(source.endsWith('/')){
                    await self.#web_search(browser, source, method, subdir).then(resolve, reject);
                }else{
                    await self.#web_done(browser, source, method).then(resolve, reject);
                }
            }
        });

        return promise;
    }

    #web_done(browser, project, source, method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            global.final.append_project(project);
            await T200Source.create_web(project, source).then(async function(obj){
                await obj.test_unit(browser).then(function(){

                }, function(err){
                    result = false;
                }).finally(function(){
       
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

    #web_flow_run(project, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let browser of self.browsers){
                await self.#web_flow_test(browser, project, source, method, subdir).then(function(){
        
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

    #web_flow_test(browser, project, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == source){
                await self.#web_flow_search(browser, project, source, method, subdir).then(resolve, reject);
            }else{
                if(source.endsWith('/')){
                    await self.#web_flow_search(browser, project, source, method, subdir).then(resolve, reject);
                }else{
                    await self.#web_flow_done(browser, project, source, method).then(resolve, reject);
                }
            }
        });

        return promise;
    }

    #web_flow_search(browser, project, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            global.final.append_project(project);
            await T200Source.create_web_case(project, source).then(async function(obj){
                await obj.test_flow(browser).then(function(){

                }, function(err){
                    result = false;
                }).finally(function(){
       
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

    #web_flow_done(browser, project, source, method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            global.final.append_project(project);
            await T200Source.create_web(project, source).then(async function(obj){
                await obj.test_flow(browser).then(function(){

                }, function(err){
                    result = false;
                }).finally(function(){
       
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


}

module.exports = T200Actuator;