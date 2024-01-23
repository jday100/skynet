const { Builder, By, until } = require("selenium-webdriver");

let browser = new Builder().forBrowser('firefox').build();

browser.get('http://localhost:8888/').then(function(){

}, function(err){

}).then(function(){
    return browser.sleep(1000);
}, function(err){

}).then(function(){
    let locate = {};
    locate.type = "css";
    locate.value = "html > body > div > fieldset > div > fieldset > div > div > div > a";
    return browser.findElements(By.css(locate.value));
}, function(err){

}).then(function(nodes){
    return nodes[0].getText();
}, function(err){

}).then(function(text){
    //return nodes[0].click();
}, function(err){

}).then(function(){
    return browser.sleep(1000);
}, function(err){

}).then(function(){

}, function(err){

});

/*
browser.getAllWindowHandles().then(function(wins){
    let length = wins.length;

    if(0 < length){
        let win = wins[length - 1];

        browser.switchTo().window(win).close();

        let element = browser.findElement(By.className(""));

        element.sendKeys("");

        browser.close();
    }    
}, function(){

});


browser.getWindowHandle().then(function(win){
    console.log(win);
    browser.close();
}, function(){

});

browser.getPageSource();

*/