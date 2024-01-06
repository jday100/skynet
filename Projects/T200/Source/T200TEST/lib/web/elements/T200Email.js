const T200Input = require('./T200Input.js');


class T200Email extends T200Input {
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
            browser.locate(self.locate.type, self.locate.value).then(function(element){
                if(element){
                    
                }else{

                }
            },function(err){

            })
        });

        return promise;
    }
}

module.exports = T200Email;