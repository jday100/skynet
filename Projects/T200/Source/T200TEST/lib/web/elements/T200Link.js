const T200Log = require('../../T200Log.js');

class T200Link {
    constructor() {

    }

    create(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.type = element.type;
            self.url = element.value;
            self.locate = '[locale="home"]';
            resolve();
        });

        return promise;
    }

    test(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            T200Log.log("link test");
            return browser.get("http://localhost:8888/register.html").then(function(){
                return browser.sleep(1000).then(function(){
                    T200Log.log("link test locate");
                    let obj = browser.locate_css(`a${self.locate}`);
                    if(obj){
                        return obj.click().then(function(){
                            return browser.sleep(1000).then(function(){
                                return browser.get_current_url().then(function(url){
                                    if(self.url == url){
                                        resolve();
                                    }else{
                                        reject();
                                    }
                                }, function(){
                                    reject();
                                });    
                            }, function(err){

                            });
                            
                        },function(){
                            reject();
                        });                                    
                    }else{
                        reject();
                    }
                });                
            }, function(err){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200Link;