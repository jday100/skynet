const { Builder, By, until } = require("selenium-webdriver");


class T200Browser {
    constructor() {
        this.browsers = new Array();
    }

    create(name) {
        let self =this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == name){
                let name = "all";
                self.#create_browser(name);
            }else{
                self.#create_browser(name);
            }

            resolve();
        });    
        
        return promise;
    }

    #create_browser(name) {
        let browser;
        switch(name){
            case 'all':
                browser = new Builder().forBrowser('firefox').build();
                if(browser){
                    this.browsers.push(browser);
                }
                browser = new Builder().forBrowser('chrome').build();
                if(browser){
                    this.browsers.push(browser);
                }
                break;
            case 'firefox':
                browser = new Builder().forBrowser('firefox').build();
                if(browser){
                    this.browsers.push(browser);
                }
                break;
            case 'chrome':
                browser = new Builder().forBrowser('chrome').build();
                if(browser){
                    this.browsers.push(browser);
                }
                break;
        }
    }

    test(web) {
        let self = this;
        let promise = new Promise(function(resolve, reject){

        });

        return promise;
    }
}

module.exports = T200Browser;