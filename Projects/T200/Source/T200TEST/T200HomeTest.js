/*
test.run();
test.run('firefox');
test.run('firefox', '/', 'run');
test.run('firefox', '/login.html', 'run');
test.run('firefox', '/login.html', 'test_case');
*/

const T200Test = require('./lib/T200Test.js');


let home = new T200Test();

home.run().then(function(){
    console.log("Success");
}, function(){
    console.log("Failure");
});

