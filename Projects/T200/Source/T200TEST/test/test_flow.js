const T200Flow = require('../lib/flow/T200Flow.js');

const { Builder, By, until } = require("selenium-webdriver");

let browser = new Builder().forBrowser('firefox').build();

let link = new T200Flow('link');

link.create().then(function(){
    link.execute(browser, link).then(function(){

    }, function(err){
        browser.close();
    });
}, function(err){

});