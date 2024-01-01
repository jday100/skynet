
/*
const T200Test = require('./lib/T200Test.js');

let test = new T200Test();

//test.run();

let name = Object.getOwnPropertyNames(Object.getPrototypeOf(test));

console.log(name);
*/

const T200Test = require('./lib/T200Test');


let test = new T200Test();

test.run();

/*
test.run('./case');
test.run('./case/T200Web.js');

test.run('./case', 'firefox');
test.run('./case/T200Web.js', 'all');
test.run('./case/T200Web.js', 'method', 'all');

or
test.run();
test.run('firefox');
test.run('firefox', '/case');
test.run('firefox', '/case/T200Web.js');
test.run('firefox', '/case/T200Web.js', 'method');

*/
