const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');

const T200Crypto = require('../../library/crypto/T200Crypto.js');



let result = T200Crypto.sha1('foo');

console.log(result.length);