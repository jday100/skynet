const T200Page = require('../../../../library/web/T200Page.js');


class T200RegisterPage extends T200Page {
    constructor(name) {
        super(name);

        this.defines = [
            "person"
        ];

        this.modules = [
            "register_form"
        ];
    }

    
    #load_data() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let name of self.defines){
                await global.data.load(name).then(function(){

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

    test_flow(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            self.browser = browser;
            await self.#load_data().then(function(){

            }, function(err){
                result = false;
            }).then(function(){
                return browser.get(browser.url(self.name))
            }, function(err){
                result = false;
            }).then(function(){
                return browser.sleep(1000);
            }, function(err){
                result = false;
            }).then(async function(){
                return self.#test_page();
            }, function(err){
                result = false;
            }).then(async function(){
                
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

    #test() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let form;

            for(let tag of self.tags){
                if("register_form" == tag.module.name){
                    form = tag;
                    break;
                }
            }

            if(undefined == form){
                reject();
            }else{
                await form.test_flow(self.browser).then(resolve, reject);
            }
        });

        return promise;
    }

    #test_page() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let form;

            for(let tag of self.tags){
                if("register_form" == tag.module.name){
                    form = tag;
                    break;
                }
            }

            if(undefined == form){
                reject();
            }else{
                await form.test_flow(self.browser).then(resolve, reject);
            }
        });

        return promise;
    }
}

module.exports = T200RegisterPage;