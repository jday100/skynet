const { Builder } = require("selenium-webdriver");

const T200Browser = require('./T200Browser');

class T200Test {
    constructor() {

    }

    run1() {
        let browser = new Builder().forBrowser('firefox').build();

        browser.get('http://localhost:8888');

        browser.sleep(1000).then(function(){
            browser.quit();
        }).catch(function(){
            browser.quit();
        });
    }

    run(browser, source, method) {
        if(undefined == browser){
            let browser = "all";
            let browsers = T200Browser.build(browser);

            for(let element of browsers){
                element.run(source, method);
            }
        }else{
            let browsers = T200Browser.build(browser);

            for(let element of browsers){
                element.run(source, method);
            }
        }
    }
}

module.exports = T200Test;