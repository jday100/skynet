class T200Password {
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

    run(browser, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            browser.locate(self.locate).then(function(element){
                if(element){
                    element.input(data).then(resolve, reject);
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