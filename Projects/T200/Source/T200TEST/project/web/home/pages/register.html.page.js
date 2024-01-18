const T200Page = require('../../../../library/web/T200Page.js');


class T200RegisterPage extends T200Page {
    constructor(name) {
        super(name);

        this.defines = [
            
        ];

        this.modules = [
            "register_form"
        ];
    }

    test_flow(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            await browser.get(browser.url(self.name)).then(function(){

            }, function(err){
                result = false;
            }).then(function(){
                return browser.sleep(1000);
            }, function(err){
                result = false;
            }).then(async function(){
                for(let tag of self.tags){
                    await tag.test_unit(browser).then(function(){

                    }, function(err){
                        result = false;
                    });
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