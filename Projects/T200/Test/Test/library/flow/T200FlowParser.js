class T200FlowParser {
    constructor(value) {
        this.value = value;
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            resolve();
        });

        return promise;
    }

    parse(browser, tag, step) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            switch(step.type){
                case 'get':
                    await self.#get(browser, tag, step).then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'wait':
                    await self.#wait(browser, tag, step).then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'get_url':
                    await self.#get_url(browser, tag, step).then(function(url){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'find':
                    await self.#find(browser, tag, step).then(function(obj){
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
                case 'save_window':
                    await self.#save_window(browser, tag, step).then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'save_all_windows':
                    await self.#save_all_windows(browser, tag, step).then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'get_new_window':
                    await self.#get_new_window(tag, step).then(function(win){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'change':
                    await self.#change(browser, tag, step).then(function(){

                    }, function(err){
                        result = false;
                    });
                    break;
                case 'close':
                    await self.#close(browser, tag, step).then(function(){

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

    #save_window(browser, element, step) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            browser.get_window().then(function(handle){
                element[step.value] = handle;
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #save_all_windows(browser, element, step) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            browser.get_all_windows().then(function(handles){
                element[step.value] = handles;
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #get_new_window(element, step) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = new Array();

            for(let win of element[step.new_values]){
                let flag = false;
                for(let old of element[step.old_values]){
                    if(win == old){
                        flag = true;
                        break;
                    }
                }
                if(flag){

                }else{
                    result.push(win);
                }
            }

            if(1 == result.length){
                element[step.value] = result[0];
                resolve(result[0]);
            }else{
                reject();
            }
        });

        return promise;
    }

    #change(browser, element, step) {
        return browser.change(element[step.value]);
    }

    #close(browser, element, step) {
        return browser.close();
    }
}

module.exports = T200FlowParser;