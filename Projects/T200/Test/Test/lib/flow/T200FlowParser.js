class T200FlowParser {
    constructor(obj) {
        this.object = obj;
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            resolve();
        });

        return promise;
    }

    parse(browser, element, step) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            switch(step.type){
                case 'get':
                    await self.#get(browser, element, step).then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'wait':
                    await self.#wait(browser, element, step).then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'get_url':
                    await self.#get_url(browser, element, step).then(function(url){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'find':
                    await self.#find(browser, element, step).then(function(obj){
                        self.element = obj;
                    }, function(err){
                        result = false;
                    });
                    break;
                case 'click':
                    await self.#click(self.element).then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
                default:
                    break;
            };

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }

    #get(browser, link, step) {
        return browser.get(browser.url(link[step.value]));
    }

    #wait(browser, link, step) {
        return browser.sleep(step.value);
    }

    #get_url(browser, link, step) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            browser.get_current_url().then(function(url){
                if(url == browser.url(link[step.value])){
                    resolve();
                }else{
                    reject();
                }
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #find(browser, link, step) {
        return browser.locate(link[step.value]);
    }

    #click(element) {
        return element.click();
    }

}

module.exports = T200FlowParser;