class T200Link {
    constructor() {

    }

    create(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.url = element.url;
            self.name = element.name;
            self.type = element.type;
            self.target = element.target;
            self.value = element.value;
            self.locate = element.locate;
            resolve();
        });

        return promise;
    }

    run(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            browser.get(browser.url(self.url)).then(function(){

            }, function(err){

            }).then(function(){
                return browser.sleep(1000);
            }, function(err){

            }).then(function(){
                return browser.locate(self.locate);
            }, function(err){

            }).then(function(element){
                if(undefined == element){

                }else{
                    return element.click();
                }
            }, function(err){

            }).then(function(){
                return browser.sleep(1000);
            }, function(err){

            }).then(function(){
                return browser.get_current_url();
            }, function(err){

            }).then(function(url){
                if(browser.current_url == browser.url(self.value)){
                    resolve();
                }else{
                    reject();
                }
            }, function(err){

            }).finally(function(){
                return browser.get(browser.url(self.url));
            });
        });

        return promise;
    }
}

module.exports = T200Link;