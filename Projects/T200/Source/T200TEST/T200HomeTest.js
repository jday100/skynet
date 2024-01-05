/*
test.run();
test.run('firefox');
test.run('firefox', '/case');
test.run('firefox', '/case/T200Web.js');
test.run('firefox', '/case/T200Web.js', 'method');
*/

const T200Test = require('./lib/T200Test.js');


let home = new T200Test();

home.run().then(function(){
    console.log("Success");
}, function(){
    console.log("Failure");
});

