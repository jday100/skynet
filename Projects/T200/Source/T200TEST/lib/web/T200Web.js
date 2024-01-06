const T200Resource = require('../T200Resource.js');


class T200Web {
    constructor(name) {
        this.name = name;
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let WebSource = T200Resource.merge_web(self.name);

            if(WebSource){
                const WebClass = require(WebSource);

                if(WebClass){
                    let WebObj = new WebClass();

                    if(WebObj){
                        WebObj.name = self.name;
                        WebObj.create().then(function(page){
                            self.page = page;
                            resolve();
                        }, function(err){
                            reject();
                        });
                    }else{
                        reject();
                    }
                }else{
                    reject();
                }
            }else{
                reject();
            }
        });

        return promise;
    }

    run(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.page.run(browser).then(resolve, reject);
        });

        return promise;
    }
}

module.exports = T200Web;