/*
test.run();
test.run('firefox');
test.run('firefox', '/', 'run');
test.run('firefox', '/login.html', 'run');
test.run('firefox', '/login.html', 'test_case');
test.run('all', '/', '*', true);
*/

const T200Test = require('./lib/T200Test.js');


let home = new T200Test();

home.run('all', '/form.html', 'test_case').then(function(){
    console.log("Success");
}, function(err){
    console.log("Failure");
}).finally(function(){
    home.report();
});

