const { Builder, By, until } = require('selenium-webdriver');

let browser = new Builder().forBrowser('firefox').build();

browser.get('http://localhost:8888/register.html').then(function(){
    browser.sleep(1000);

    let obj = browser.findElement(By.css('a[locale="home"]'));
    
    if(undefined == obj){
    
    }else{
        obj.click();
    
        browser.sleep(1000);
    
        //console.log(browser.getCurrentUrl());
        browser.getCurrentUrl().then(function(data){
            console.log(data);
            //browser.quit();
        });
    }
});


