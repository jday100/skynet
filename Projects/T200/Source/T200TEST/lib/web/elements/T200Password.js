const T200Input = require('./T200Input.js');


class T200Password extends T200Input {
    constructor() {
        super();
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
            browser.get(`${browser.root}${self.url}`).then(function(){

            }, function(err){

            }).then(function(){
                return browser.sleep(1000);
            },function(){

            }).then(function(){
                return browser.locate(self.locate.type, self.locate.value);
            },function(){

            }).then(function(element){
                if(element){
                    return browser.click(self.target, element);
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
                let result = `${browser.root}${self.value}`;
                if(result == url){
                    resolve();
                }else{
                    console.log(`${self.name} ${result}`);
                    reject();
                }
            },function(){

            }).finally(function(){
                return browser.get(`${browser.root}${self.url}`);
            });
        });

        return promise;
    }
}

module.exports = T200Password;