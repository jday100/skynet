const T200Case = require('../../../library/T200Case.js');


class T200RegisterCase extends T200Case {
    constructor() {
        super();
        this.name = "/register.html";
    }

    test_unit(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(self.page){
                await self.create_store().then(function(){

                }, function(err){

                }).then(function(){
                    return self.#clear_data();
                }, function(err){

                }).then(function(){
                    return self.page.test_unit(browser);
                }, function(err){

                }).then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
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
}

module.exports = T200RegisterCase;