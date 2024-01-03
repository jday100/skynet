const T200Web = require('./lib/web/T200Web.js');
const T200Browser = require('./lib/T200Browser.js');


let browser = new T200Browser();


browser.create('firefox').then(function(){  
    let web = new T200Web("/login.html");
    
    web.create().then(function(){
        web.test(browser).then(function(){
            console.log('Success');
        }, function(err){
            console.log('Failure');
        });
    }, function(err){
    
    });
}, function(err){

});








