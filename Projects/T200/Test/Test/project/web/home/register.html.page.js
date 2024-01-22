const T200Page = require('../../../library/web/T200Page.js');


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

    run(browser){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let form;

            await browser.get(browser.url(self.name)).then(function(){

            }, function(err){
                result = false;
            });

            if(result){
                for(let module of self.module_values){
                    if("register_form" == module.name){
                        form = module;
                        break;
                    }
                }
    
                if(undefined == form){
                    reject();
                }else{
                    await form.run(browser).then(resolve, reject);
                }
            }else{
                reject();
            }            
        });

        return promise;
    }
}

module.exports = T200RegisterPage;