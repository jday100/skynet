const { Builder } = require("selenium-webdriver");

class T200Test {
    constructor() {

    }

    run() {
        let browser = new Builder().forBrowser('firefox').build();

        browser.get('http://localhost:8888');

        browser.sleep(1000).then(function(){
            browser.quit();
        }).catch(function(){
            browser.quit();
        });
    }
}

module.exports = T200Test;