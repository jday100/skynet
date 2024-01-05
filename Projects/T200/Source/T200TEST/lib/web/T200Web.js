const T200Resource = require('../T200Resource.js');
const T200Define = require('../../lib/T200Define.js');

class T200Web {
    constructor(name) {
        this.name = name;
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let web_source = T200Resource.merge_web(self.name);

            if(web_source){
                const WebClass = require(web_source);

                if(WebClass){
                    let web_obj = new WebClass();

                    if(web_obj){
                        web_obj.create().then(function(page){
                            self.page = page;
                            resolve();
                        }, function(){

                        });
                    }
                }
            }
        });

        return promise;
    }

    test(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.page.test(browser).then(function(){
                resolve();
            }, function(){

            });
        });

        return promise;
    }

}

module.exports = T200Web;