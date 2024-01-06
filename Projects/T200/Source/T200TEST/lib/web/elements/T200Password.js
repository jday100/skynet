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

    run(browser, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            browser.locate(self.locate.type, self.locate.value).then(function(element){
                if(element){
                    element.sendKeys(data);
                    resolve();
                }else{
                    reject();
                }
            },function(err){
                reject();
            })
        });

        return promise;
    }
}

module.exports = T200Password;