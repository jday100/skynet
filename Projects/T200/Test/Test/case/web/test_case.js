const T200Web = require('../../lib/web/T200Web.js');


class T200WebTestCase {
    constructor() {
        this.html = [
            "/link.html",
            "/form.html"
        ];

        this.cases = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let url of self.html){
                let web = new T200Web(url);

                if(web){
                    await web.create().then(function(){
                        self.cases.push(web);
                        resolve();
                    }, function(err){
                        reject();
                    });
                }else{
                    reject();
                }
            }
        });

        return promise;
    }

    test_case(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let web of self.cases){
                await web.test_case(browser).then(function(){
                    
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

    run(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let web of self.cases){
                await web.run(browser).then(function(){
                    
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
}

module.exports = T200WebTestCase;