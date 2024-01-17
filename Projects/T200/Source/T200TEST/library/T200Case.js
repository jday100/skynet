const T200Source = require('./T200Source.js');
const T200Store = require('./db/T200Store.js');


class T200Case {
    constructor() {

    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Source.create_web_page(self.project, self.name).then(function(value){
                self.page = value;
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    create_store() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let store = new T200Store();

            await store.create().then(function(){
                self.store = store;
                resolve();
            }, function(){
                reject();
            });
        });

        return promise;
    }

    test_flow(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }
    
    test_unit(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(self.page){
                await self.page.test_unit(browser).then(function(){
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
}

module.exports = T200Case;