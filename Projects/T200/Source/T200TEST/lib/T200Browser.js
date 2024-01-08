const T200WebSetup = require('../project/T200WebSetup.js');
const { Builder, By, until } = require("selenium-webdriver");


class T200Browser {
    constructor() {

    }

    static create(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let value;
            let result = true;
            let browsers = new Array();
            let browser;

            if(undefined == name){
                value = "all";
            }else{
                value = name;
            }

            switch(value){
                case 'all':
                    browser = self.#create_browser('firefox');
                    if(browser){
                        browsers.push(browser);
                    }else{
                        result = false;
                    }

                    if(result){
                        resolve(browsers);
                        return;
                    }
                    break;
                case 'firefox':
                    browser = self.#create_browser(value);
                    if(browser){
                        browsers.push(browser);
                        resolve(browsers);
                        return;
                    }
                    break;
            }
            reject();
        });

        return promise;
    }

    static #create_browser(name) {
        let result;
        let browser = new Builder().forBrowser(name).build();

        if(browser){
            result = new T200Browser(browser);
        }

        return result;
    }
}

module.exports = T200Browser;