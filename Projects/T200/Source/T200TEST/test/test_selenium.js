const { Builder, By, until } = require("selenium-webdriver");

let browser = new Builder().forBrowser('firefox').build();

browser.getAllWindowHandles().then(function(wins){
    let length = wins.length;

    if(0 < length){
        let win = wins[length - 1];

        browser.switchTo().window(win);

        browser.findElement(By.className(""));
    }    
}, function(){

});