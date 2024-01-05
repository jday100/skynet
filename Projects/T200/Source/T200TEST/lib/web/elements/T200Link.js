class T200Link {
    constructor() {

    }

    create(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.url = element.url;
            self.type = element.type;
            self.value = element.value;
            self.locate_type = element.locate_type;
            self.locate_value = element.locate_value;
            resolve();
        });

        return promise;
    }

    run(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            browser.get(self.url).then(function(){

            }, function(){

            }).then(function(){
                return browser.sleep(1000);
            },function(){

            }).then(function(){
                return browser.locate(self.locate_type, self.locale_value);
            },function(){

            }).then(function(element){
                if(element){
                    return browser.click(element);
                }else{

                }
            },function(){

            }).then(function(){
                return browser.sleep(1000);
            },function(){

            }).then(function(){
                return browser.get_current_url();
            },function(){

            }).then(function(url){
                if(self.value == url){
                    resolve();
                }else{
                    reject();
                }
            },function(){

            }).finally(function(){
                return browser.get(self.url);
            });
        });

        return promise;
    }
}

module.exports = T200Link;