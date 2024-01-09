const T200Page = require('../../lib/web/T200Page.js');
const T200Form  = require('../../lib/web/T200Form.js');


class T200RegisterPage extends T200Page {
    constructor(name) {
        super(name);

        this.object_defines = [
            "person"
        ];

        this.module_defines = [
            "nav",
            "channel",
            "register_form"
        ];

        this.objects = new Array();
        this.modules = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let name of self.module_defines){
                await self.create_module(name).then(function(){
                    
                }, function(err){
                    result = false;
                });
            }

            if(result){
                await self.create_store().then(async function(){
                    await self.#clear_data().then(function(){

                    }, function(err){
                        result = false;
                    });
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

    #clear_data() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let sql = "delete from person where user_id != 1";
            
            await self.store.connect().then(async function(){
                await self.store.execute(sql).then(function(){

                },function(err){
                    console.log(err);
                    result = false;
                }).finally(async function(){
                    await self.store.disconnect().then(function(){

                    },function(err){
                        result = false;
                    });
                });
            },function(err){
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

    run(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            await browser.get(browser.url(self.name)).then(async function(){
                for(let element of self.elements){
                    if(element instanceof T200Form){
                        await element.run(browser).then(function(){
    
                        }, function(err){
                            result = false;
                        });
                    }              
                }                
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

module.exports = T200RegisterPage;