const T200Setup = require('../project/T200Setup.js');

const T200Path = require(T200Setup.external('./library/fs/T200Path.js'));
const T200Source = require('./T200Source.js');
const { Builder } = require("selenium-webdriver");


class T200Browser {
    constructor(browser) {
        this.event = {};
        switch(browser){
            case 'firefox':
                this.browser = new Builder().forBrowser('firefox').build();
                break;
        }
    }

    static build(browser) {
        let result = new Array();

        if(undefined == browser){
            let browser = "all";

            switch(browser){
                case "firefox":
                    result.push(new T200Browser(browser));
                    break;
                case "chrome":
                    result.push(new T200Browser(browser));
                    break;
                case "all":
                    result.push(new T200Browser("firefox"));
                    break;
                case "none":
                    result.push(new T200Browser("firefox"));
                    result.push(new T200Browser("chrome"));
                    break;
            }
        }else{
            switch(browser){
                case "firefox":
                    result.push(new T200Browser(browser));
                    break;
                case "chrome":
                    result.push(new T200Browser(browser));
                    break;
                case "all":
                    result.push(new T200Browser("firefox"));
                    break;
                case "none":
                    result.push(new T200Browser("firefox"));
                    result.push(new T200Browser("chrome"));
                    break;
            }
        }

        return result;
    }

    on(name, callback) {
        this.event[name] = callback;
    }

    run(source, method) {
        let self = this;

        this.on("start", function(){
            self.root.start();
        });

        this.on("stop", function(){

        });

        if(undefined == source){
            source = "";
            
            T200Path.is_dir(source).then(function(){

            }, function(){
                let obj = new T200Source();
    
                obj.run(source, method);
            });
        }else{
            T200Path.is_dir(source).then(function(result){
                if(result){

                }else{
                    let obj = new T200Source();
                    obj.browser = self;

                    self.event['start']();
                    obj.run(source, method);
                }
            }, function(){
                
            });
        }
    }

    get(url) {
        this.browser.get(url);
    }
}

module.exports = T200Browser;