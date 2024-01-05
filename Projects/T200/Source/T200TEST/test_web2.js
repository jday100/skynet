const T200Web = require('./lib/web/T200Web.js');
const T200Browser = require('./lib/T200Browser.js');
const T200Log = require('./lib/T200Log.js');

let browser;

T200Browser.create('firefox').then(function(browsers){  
    let web = new T200Web("/login.html");
    
    return web.create().then(function(){
        browser = browsers[0];
        return web.test(browser).then(function(){
            //T200Log.result("Success");
        }, function(err){
            //T200Log.result("Failure");
        });
    }, function(err){
    
    });
}, function(err){

}).finally(function(){
    T200Log.result("Success");
});








