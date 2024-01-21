const T200Test = require('./library/core/T200Test.js');

let Home = new T200Test();

Home.run("web", "home", "firefox", "scan.script", "all").then(function(){
    console.log("success");
}, function(err){
    console.log("failure");
}).finally(function(){
    
});