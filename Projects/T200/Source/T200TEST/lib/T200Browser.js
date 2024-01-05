const { Builder, By, until } = require("selenium-webdriver");

class T200Browser {
    constructor(browser) {
        this.browser = browser;
        this.root = "http://localhost:8888";
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

    get(url) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browser.get(url).then(function(){
                self.browser.getCurrentUrl().then(function(url){
                    self.current_url = url;
                    resolve();
                }, function(){
                    self.current_url = "";
                    reject();
                });
            }, function(err){
                self.current_url = "";
                reject();
            });
        });

        return promise;
    }

    sleep(value) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browser.sleep(value).then(resolve, reject);
        });

        return promise;
    }

    locate(type, value) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            switch(type){
                case 'css':
                    let result = self.browser.findElement(By.css(value));

                    if(result){
                        resolve(result);
                    }else{
                        reject();
                    }
                    break;
                default:
                    reject();
            }
        });

        return promise;
    }

    click(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            element.click().then(function(){
                self.browser.getCurrentUrl().then(function(url){
                    self.current_url = url;
                    resolve();
                }, function(){
                    self.current_url = "";
                    reject();
                });
            }, function(){
                self.current_url = "";
                reject();
            });
        });

        return promise;
    }

    get_current_url() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            resolve(self.current_url);
        });

        return promise;
    }
}

module.exports = T200Browser;