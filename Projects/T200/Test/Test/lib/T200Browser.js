const T200WebSetup = require('../project/T200WebSetup.js');
const { Builder, By, until } = require("selenium-webdriver");
const T200Element = require('./T200Element.js');
const { elementIsDisabled } = require('selenium-webdriver/lib/until.js');


class T200Browser {
    constructor(browser) {
        this.browser = browser;
        this.root = T200WebSetup.url();
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

    get(url) {
        let self = this;
        return self.browser.get(url);
    }

    sleep(value) {
        let self = this;
        return self.browser.sleep(value);
    }   

    locate(locate) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result;

            switch(locate.type){
                case 'css':
                    result = self.browser.findElement(By.css(locate.value));

                    if(result){
                        resolve(new T200Element(result));
                    }else{
                        reject();
                    }
                    break;
                case 'class':
                    result = self.browser.findElement(By.className(locate.value));

                    if(result){
                        resolve(new T200Element(result));
                    }else{
                        reject();
                    }
                    break;
                case 'name':
                    result = self.browser.findElement(By.name(locate.value));

                    if(result){
                        resolve(new T200Element(result));
                    }else{
                        reject();
                    }
                    break;
                case 'id':
                    result = self.browser.findElement(By.id(locate.value));

                    if(result){
                        resolve(new T200Element(result));
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

    get_current_url() {
        let self = this;
        return self.browser.getCurrentUrl();
    }

    url(url) {
        return `${this.root}${url}`;
    }

    get_window() {
        let self = this;
        return self.browser.getWindowHandle();
    }

    get_all_windows() {
        let self = this;
        return self.browser.getAllWindowHandles();
    }

    change(handle) {
        let self = this;
        return self.browser.switchTo().window(handle);
    }

    close_window() {
        let self = this;
        return self.browser.close();
    }

    close() {
        let self = this;
        return self.browser.close();
    }

}

module.exports = T200Browser;