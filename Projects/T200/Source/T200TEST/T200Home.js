const T200Test = require('./lib/T200Test.js');

let test = new T200Test();

//test.run();

let name = Object.getOwnPropertyNames(Object.getPrototypeOf(test));

console.log(name);
