const T200Browser = require('../web/T200Browser.js');
const T200HtmlParser = require('./T200HtmlParser.js');


class T200Sketch {
    constructor() {

    }

    static create(category, project, source, name) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let browser;
            await T200Browser.create('firefox').then(function(browsers){
                if(browsers && 1 == browsers.length){
                    browser = browsers[0];
                    return browser.get(browser.url(source));
                }else{
                    
                }
            }, function(err){

            }).then(function(){
                return browser.sleep(1000);
            }, function(err){

            }).then(function(){
                return browser.get_current_url();
            }, function(err){

            }).then(function(url){
                if(url == browser.url(source)){

                }else{

                }
            }, function(err){
                
            }).then(function(){
                return browser.html();
            }, function(err){

            }).then(function(html){
                return self.#parse(html);
            }, function(err){

            }).then(function(){
                return browser.close();
            }, function(err){

            }).then(function(){
    
            }, function(err){

            });
        });

        return promise;
    }

    static #parse(html) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let parser = new T200HtmlParser();

            parser.parse(html);
        });

        return promise;
    }
}

module.exports = T200Sketch;