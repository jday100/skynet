const { Builder, By, until } = require("selenium-webdriver");
const T200WebSetup = require('../../project/T200WebSetup.js');
const T200Node = require('./T200Node.js');
const { elementTextContains } = require("selenium-webdriver/lib/until.js");


class T200Browser {
    constructor(browser) {
        this.browser = browser;
        this.root = T200WebSetup.url();
    }

    static create(type) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            switch(type){
                case undefined:
                case 'all':
                    await self.#create_all_browsers().then(function(browsers){
                        resolve(browsers);
                    }, function(err){
                        reject();
                    });
                    break;
                case 'firefox':
                    await self.#create_browser('firefox').then(function(browser){
                        let result = new Array();
                        result.push(browser);
                        resolve(result);
                    }, function(err){
                        reject();
                    });
                    break;
            }
        });

        return promise;
    }

    static #create_all_browsers() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    static #create_browser(type) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let browser = new Builder().forBrowser(type).build();

            if(browser){
                let result = new T200Browser(browser);
                resolve(result);
            }else{
                reject();
            }  
        });

        return promise;
    }

    get(url) {
        return this.browser.get(url);
    }

    sleep(value) {
        return this.browser.sleep(value);
    }

    locate(locate) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result;

            switch(locate.type){
                case 'css':
                    result = self.browser.findElement(By.css(locate.value));
                    break;
                case 'class':
                    result = self.browser.findElement(By.className(locate.value));
                    break;
                case 'name':
                    result = self.browser.findElement(By.name(locate.value));
                    break;
                case 'id':
                    result = self.browser.findElement(By.id(locate.value));
                    break;
            }

            if(result){
                resolve(new T200Node(result));
            }else{
                reject();
            }
        });

        return promise;
    }

    get_current_url() {
        return this.browser.getCurrentUrl();
    }

    url(url) {
        return `${this.root}${url}`;
    }

    get_window() {
        return this.browser.getWindowHandle();
    }

    get_all_windows() {
        return this.browser.getAllWindowHandles();
    }

    change(handle) {
        return this.browser.switchTo().window(handle);
    }

    close_window() {
        return this.browser.close();
    }

    close() {
        return this.browser.close();
    }
}

module.exports = T200Browser;