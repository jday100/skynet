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

    get(url) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browsers[0].get(url).then(function(){
                self.browsers[0].getCurrentUrl().then(function(url){
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
        this.browsers[0].sleep(value);
    }

    locate() {

    }

    locate_css(value) {
        return this.browsers[0].findElement(By.css(value));
    }

    get_current_url() {
        return this.browsers[0].getCurrentUrl();
    }
}

module.exports = T200Browser;