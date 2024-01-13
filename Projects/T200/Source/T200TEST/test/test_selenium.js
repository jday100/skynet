const { Builder, By, until } = require("selenium-webdriver");

let browser = new Builder().forBrowser('firefox').build();

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
*/

browser.getWindowHandle().then(function(win){
    console.log(win);
    browser.close();
}, function(){

});