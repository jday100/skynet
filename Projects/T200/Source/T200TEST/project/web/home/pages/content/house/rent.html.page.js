const T200Page = require('../../../../../../library/web/T200Page.js');


class T200HouseRentPage extends T200Page {
    constructor(name) {
        super(name);

        this.defines = [
        ];

        this.modules = [
            "content/house/rent_list"
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
            await self.#click("publish").then(function(){

            }, function(err){
                result = false;
            }).then(function(){
                return browser.sleep(500);
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


    #click(name) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let value;
            for(let tag of self.tags){
                if(name == tag.field.name){
                    value = tag;
                    break;
                }
            }

            if(undefined == value){
                reject();
            }else{
                await value.run(self.browser).then(resolve, reject);
            }
        });

        return promise;
    }
}

module.exports = T200HouseRentPage;