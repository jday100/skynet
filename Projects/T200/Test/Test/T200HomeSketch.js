const T200Test = require('./library/core/T200Test.js');

T200Test.sketch("web", "home", "/house/index.html", "house/index").then(function(){
    console.log("success");
}, function(err){
    console.log("failure");
}).finally(function(){
    
});