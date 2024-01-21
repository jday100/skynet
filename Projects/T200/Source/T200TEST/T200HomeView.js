const T200Test = require('./library/T200Test.js');

let home = new T200Test();

home.test("web", "home", "firefox", "/", "test_view").then(function(){
    console.log('success');
}, function(err){
    console.log('failure');
}).finally(function(){
    home.report();
});