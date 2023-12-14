const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');


const crypto = require('crypto');


class T200Crypto {
    constructor() {

    }

    static sha1(value) {
        let obj = crypto.createHash('sha1');
        obj.update(value);
        let result = obj.digest('hex');

        console.log(result);
        return result;
    }
}

module.exports = T200Crypto;