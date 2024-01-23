const T200Page = require('../../../../library/web/T200Page.js');


class T200HouseIndexPage extends T200Page {
    constructor(name) {
        super(name);

        this.url = "/house/index.html";

        this.defines = [
            
        ];

        this.modules = [
            "nav",
            "house/house_index"
        ];
    }

    run(browser, options){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let module = self.module_values[0];

            await browser.get(browser.url(self.url)).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }


    house_index(browser, options){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let module = self.module_values[1];

            if(options && options.module){
                await module[options.module](browser, options).then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }else{
                await module.run(browser, options).then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }            
        });

        return promise;
    }
}

module.exports = T200HouseIndexPage;