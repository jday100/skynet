const T200Page = require('../../lib/web/T200Page.js');
const T200Form  = require('../../lib/web/T200Form.js');


class T200LoginPage extends T200Page {
    constructor(name) {
        super(name);

        this.object_defines = [
            "person"
        ];

        this.module_defines = [
            "nav",
            "channel",
            "login_form"
        ];

        this.objects = new Array();
        this.modules = new Array();
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

module.exports = T200LoginPage;