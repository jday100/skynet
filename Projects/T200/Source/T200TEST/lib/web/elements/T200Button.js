class T200Button {
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
            browser.locate(self.locate).then(function(element){
                if(element){
                    return element.click();
                }else{
                    reject();
                }
            },function(err){
                reject();
            }).then(function(){
                resolve();
            }, function(){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200Button;