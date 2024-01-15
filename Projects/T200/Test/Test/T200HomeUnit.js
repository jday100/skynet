const T200Test = require('./library/T200Test.js');

let home = new T200Test();

home.unit("web", "home", "firefox", "/link.html").then(function(){
    console.log('success');
}, function(err){
    console.log('failure');
}).finally(function(){
    home.report();
});