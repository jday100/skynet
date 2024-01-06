const T200WebSetup = require('../project/T200WebSetup.js');
const { Builder, By, until, TargetLocator } = require("selenium-webdriver");

class T200Browser {
    constructor(browser) {
        this.browser = browser;
        this.root = T200WebSetup.url();
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
            let result;

            switch(type){
                case 'css':
                    result = self.browser.findElement(By.css(value));

                    if(result){
                        resolve(result);
                    }else{
                        reject();
                    }
                    break;
                case 'class':
                    result = self.browser.findElement(By.className(value));

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

    click(target, element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            element.click().then(function(){
                if(undefined == target){
                    self.browser.getCurrentUrl().then(function(url){
                        self.current_url = url;
                        resolve();
                    }, function(){
                        self.current_url = "";
                        reject();
                    });
                }else if("blank" == target){
                    self.browser.sleep(1000).then(function(){
                        self.browser.getAllWindowHandles().then(function(wins){
                            let length = wins.length;
    
                            if(0 < length){
                                let win = wins[length - 1];
    
                                if(win){
                                    self.browser.switchTo().window(win).then(function(){
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
                                }else{
                                    self.current_url = "";
                                    reject();
                                }
                            }else{
                                self.current_url = "";
                                reject();
                            }
                        }, function(){
                            self.current_url = "";
                            reject();
                        }); 
                    }, function(){
                        self.current_url = "";
                        reject();
                    });                                       
                }                
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