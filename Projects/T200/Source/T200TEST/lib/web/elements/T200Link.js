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
            browser.get("http://localhost:8888/register.html").then(function(){
                browser.sleep(1000);
                let obj = browser.locate_css(`a${self.locate}`);
                if(obj){
                    obj.click().then(function(){
                        browser.sleep(1000);

                        browser.get_current_url().then(function(url){
                            if(self.url == url){
                                resolve();
                            }else{
                                reject();
                            }
                        }, function(){
                            reject();
                        });    
                    },function(){
                        reject();
                    });                                    
                }else{
                    reject();
                }
            }, function(){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200Link;