const { Builder, By, until } = require("selenium-webdriver");

class T200Browser {
    constructor(browser) {
        this.browser = browser;
    }

    static create(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let browsers = new Array();
            let browser;

            switch(name){
                case 'all':
                    let result = true;
                    browser = new Builder().forBrowser('firefox').build();
                    if(browser){
                        let obj = new T200Browser(browser);
                        browsers.push(obj);
                    }else{
                        result = false;
                    }
                    if(result){
                        resolve(browsers);
                        return;
                    }
                    break;
                case 'firefox':
                    browser = new Builder().forBrowser('firefox').build();
                    if(browser){
                        let obj = new T200Browser(browser);
                        browsers.push(obj);
                        resolve(browsers);
                        return;
                    }
                    break;
                case 'chrome':
                    break;
            }

            reject();
        });

        return promise;
    }
}

module.exports = T200Browser;