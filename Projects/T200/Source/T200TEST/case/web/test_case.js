const T200Web = require('../../lib/web/T200Web.js');


class T200WebTestCase {
    constructor() {
        this.html = [
            //"/register.html",
            "/login.html"
        ];
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            resolve();
        });

        return promise;
    }

    test_case() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let url of self.html){
                let web = new T200Web(url);

                if(web){
                    await web.create().then(function(){

                    }, function(err){
                        result = false;
                    });
                }
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