class T200Actuator {
    constructor() {

    }

    test_unit(category, type, name, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == category){
                await self.#test_all().then(function(){

                }, function(err){

                });
            }else{
                switch(category){
                    case 'all':
                        await self.#test_all(type, name, method, subdir).then(function(){

                        }, function(err){
        
                        });
                        break;
                    case 'app':
                        await self.#test_app(type, name, method, subdir).then(function(){

                        }, function(err){
        
                        });
                        break;
                    case 'web':
                        await self.#test_web(type, name, method, subdir).then(function(){

                        }, function(err){
        
                        });
                        break;
                }
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

    #test_web(type, name, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            await self.#web_start(type).then(async function(){
                await self.#web_run(name, method, subdir).then(function(){

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

    #web_start(type, name, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == type){
                await self.#test_web_all(name, method, subdir).then(function(){

                }, function(err){
                    
                });
            }else{

            }
        });

        return promise;
    }

    #web_stop(type, name, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == type){
                await self.#test_web_all(name, method, subdir).then(function(){

                }, function(err){
                    
                });
            }else{

            }
        });

        return promise;
    }

    #create_web_all(type, name, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == type){
                await self.#test_web_all(name, method, subdir).then(function(){

                }, function(err){
                    
                });
            }else{

            }
        });

        return promise;
    }

    #create_web_firefox(type, name, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == type){
                await self.#test_web_all(name, method, subdir).then(function(){

                }, function(err){
                    
                });
            }else{

            }
        });

        return promise;
    }

    #web_run(name, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let browser of self.browsers){
                await self.#web_test(name, method, subdir).then(function(){

                }, function(err){

                });
            }
        });

        return promise;
    }

    #web_test(browser, source, method, subdir) {
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

    #web_search(browser, source, method, subdir) {
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

    #web_done(browser, source, method) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            T200Source.create_web(source).then(function(obj){
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