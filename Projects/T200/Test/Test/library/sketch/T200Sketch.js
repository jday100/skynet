const T200Browser = require('../web/T200Browser.js');
const T200HtmlParser = require('./T200HtmlParser.js');
const T200Resource = require('../core/T200Resource.js');
const T200Setup = require('../../config/T200Setup.js');
const T200File = require(T200Setup.external('./library/fs/T200File.js'));


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

            }).then(function(value){
                return self.#save(value, category, project, name);
            }, function(err){

            }).then(function(){
                return browser.close();
            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    static #parse(html) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let parser = new T200HtmlParser();

            await parser.parse(html).then(function(value){
                resolve(value);
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    static #save(value, category, project, name) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_sketch(category, project, name);

            if(file){
                await T200File.save(file, value).then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }
}

module.exports = T200Sketch;