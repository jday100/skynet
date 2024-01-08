const T200Resource = require('./T200Resource.js');


class T200Case {
    constructor() {

    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let PageSource = T200Resource.merge_web_page(self.url);

            if(PageSource){
                let PageClass = require(PageSource);

                if(PageClass){
                    let PageObj = new PageClass(self.url);

                    if(PageObj){
                        PageObj.create().then(function(){
                            self.page = PageObj;
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
            if(self.page){
                self.page.run(browser).then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }
}

module.exports = T200Case;