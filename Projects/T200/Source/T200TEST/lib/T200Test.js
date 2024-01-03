const T200Setup = require('../project/T200Setup.js');

const T200Path = require(T200Setup.external('./library/fs/T200Path.js'));

const { Builder } = require("selenium-webdriver");

const T200Browser = require('./T200Browser');

const process = require('child_process');


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
        let self = this;
        if(undefined == browser){
            let browser = "all";
            let browsers = T200Browser.build(browser);

            for(let element of browsers){
                element.run(source, method);
            }
        }else{
            let browsers = T200Browser.build(browser);

            for(let element of browsers){
                element.root = this;
                element.run(source, method);
            }
        }
    }

    start() {
        let self = this;
        setTimeout(() => {
            ///const T200Home = require(T200Setup.external('./T200Home.js'));

            self.server = process.exec(`cd ../web/ && node ./T200Home.js`);
        });
    }

    stop() {
        let self = this;

        if(undefined == self.server){

        }else{
            self.server.kill();
        }
        
    }
}

module.exports = T200Test;