const T200Page = require('../../../library/web/T200Page.js');


class T200LoginPage extends T200Page {
    constructor(name) {
        super(name);

        this.defines = [
            "person"
        ];

        this.modules = [
            "login_form"
        ];
    }

    run(browser){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let module = self.module_values[0];

            await browser.get(browser.url(self.name)).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }


    form(browser, options){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let module = self.module_values[0];

            await module.run(browser, options).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200LoginPage;