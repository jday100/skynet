const T200Setup = require('../project/T200Setup.js');

const T200Path = require(T200Setup.external('./library/fs/T200Path.js'));
const T200File = require(T200Setup.external('./library/fs/T200File.js'));

const { Builder } = require("selenium-webdriver");

const T200Browser = require('./T200Browser');
const T200Source = require('./T200Source.js');
const T200Resource = require('./T200Resource.js');

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

            T200Browser.create(browser).then(function(browsers){
                self.browsers = browsers;
                if(undefined == source){
                    self.#search(browsers);
                }else{
                    self.#done(browsers, source, method);
                }                
            }, function(err){

            });            
        }else{
            T200Browser.create(browser).then(function(browsers){
                self.browsers = browsers;
                if(undefined == source){
                    self.#search(browsers);
                }else{
                    self.#done(browsers, source, method);
                } 
            }, function(err){

            }); 
        }
    }

    #done(browsers, source, method) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let obj = new T200Source(source);

            obj.create().then(function(){

            }, function(){

            });

            for(let element of browsers){
                //element.root = this;
                //element.run(source, method);
            }
        });

        return promise;
    }

    #search(browsers) {
        let self = this;
        let index = T200Resource.merge_case('index.html');

        if(index){
            T200File.exists(index).then(function(){
                let dir = T200Resource.merge_case('.');

                if(dir){
                    T200Path.list(dir).then(function(data){
                        for(let file of data.files){
                            let source = new T200Source(file);

                            source.create().then(function(){

                            }, function(){

                            });
                        }
                    }, function(){
        
                    });
                }
            }, function(){
                let dir = T200Resource.merge_case_dir('.');

                if(dir){
                    T200Path.list(dir).then(function(data){
                        for(let file of data.files){
                            let source = new T200Source(file);

                            source.create().then(function(data){
                                self.#execute(source, data);
                            }, function(err){

                            });
                        }
                    }, function(){
        
                    });
                }
            });
        }        
    }


    #execute(source, methods) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            for(let browser of self.browsers){
                for(let method of methods){
                    source.run(browser, method);
                }
            }
        });

        return promise;
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