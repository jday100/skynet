const T200Test = require('./library/T200Test.js');

let home = new T200Test();

home.flow("web", "home", "firefox").then(function(){
    console.log('success');
}, function(err){
    console.log('failure');
}).finally(function(){
    home.report();
});