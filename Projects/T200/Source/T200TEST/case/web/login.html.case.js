const T200Web = require('../../lib/web/T200Web.js');


class T200LoginCase {
    constructor() {
        this.url = "/login.html";
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let web = new T200Web(self.url);

            web.create().then(function(){
                self.web = web;
                resolve();
            }, function(){
                reject();
            });
        });

        return promise;
    }

    run_login(browser) {
        
    }
}

module.exports = T200LoginCase;