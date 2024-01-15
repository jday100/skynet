const { Builder, By, until } = require("selenium-webdriver");
const T200WebSetup = require('../../project/T200WebSetup.js');
const T200Node = require('./T200Node.js');


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
}

module.exports = T200Browser;