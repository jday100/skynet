const { Builder, By, until } = require("selenium-webdriver");


class T200Browser {
    constructor(browser) {
        this.browser = browser;
    }

    static create(name) {
        let self =this;
        let promise = new Promise(function(resolve, reject){
            let result;
            if(undefined == name){
                let name = "all";
                result = self.#create_browser(name);
            }else{
                result = self.#create_browser(name);
            }

            resolve(result);
        });    
        
        return promise;
    }

    static #create_browser(name) {
        let browsers = new Array();
        let browser;
        switch(name){
            case 'all':
                browser = new Builder().forBrowser('firefox').build();
                if(browser){
                    let obj = new T200Browser(browser);
                    browsers.push(obj);
                }
                /*
                browser = new Builder().forBrowser('chrome').build();
                if(browser){
                    let obj = new T200Browser(browser);
                    browsers.push(obj);
                }
                */
                break;
            case 'firefox':
                browser = new Builder().forBrowser('firefox').build();
                if(browser){
                    let obj = new T200Browser(browser);
                    browsers.push(obj);
                }
                break;
            case 'chrome':
                browser = new Builder().forBrowser('chrome').build();
                if(browser){
                    let obj = new T200Browser(browser);
                    browsers.push(obj);
                }
                break;
        }

        return browsers;
    }

    test(web) {
        let self = this;
        let promise = new Promise(function(resolve, reject){

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
                    self.current_url = '';
                    reject();
                });
            }, function(){
                self.current_url = '';
                reject();
            });
        });

        return promise;
    }

    sleep(value) {
        return this.browser.sleep(value);
    }

    locate() {

    }

    locate_css(value) {
        return this.browser.findElement(By.css(value));
    }

    get_current_url() {
        return this.browser.getCurrentUrl();
    }
}

module.exports = T200Browser;