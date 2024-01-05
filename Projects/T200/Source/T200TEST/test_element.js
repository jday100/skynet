const T200Link = require('./lib/web/elements/T200Link.js');
const T200Browser = require('./lib/T200Browser.js');

let browser;

T200Browser.create('firefox').then(function(browsers){  
    let element = new T200Link();
    
    browser = browsers[0];
    element.create().then(function(){
        element.test(browser).then(function(){
            console.log('Success');
        }, function(err){
            console.log('Failure');
        });
    }, function(){
    
    });
}, function(){

});








