const T200Web = require('./web/T200Web.js');


class T200Case {
    constructor() {
        this.url = "";
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let web = new T200Web(self.url);

            if(web){
                web.create().then(function(){
                    self.web = web;
                    resolve();
                }, function(){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }

    run_login(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.web.run(browser).then(resolve, reject);  
        });

        return promise;
    }
}

module.exports = T200Case;