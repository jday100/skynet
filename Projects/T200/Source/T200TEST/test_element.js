const T200Link = require('./lib/web/elements/T200Link.js');
const T200Browser = require('./lib/T200Browser.js');


let browser = new T200Browser();


browser.create('firefox').then(function(){  
    let element = new T200Link();
    
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








