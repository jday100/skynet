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


    static encrypt_aes(data) {
        let key = '01234567890123456789012345678901';
        let iv = '0123456789012345';
        let cipher = crypto.createCipheriv('aes-256-cbc', key, iv);

        cipher.setAutoPadding(true);
        let result = cipher.update(data, 'utf8', 'base64');

        result += cipher.final('base64');

        return result;
    }

    static decrypt_aes(data) {
        let key = '01234567890123456789012345678901';
        let iv = '0123456789012345';
        let cipher = crypto.createDecipheriv('aes-256-cbc', key, iv);

        cipher.setAutoPadding(true);
        let result = cipher.update(data, 'base64', 'utf8');

        result += cipher.final('utf8');

        return result;
    }
}

module.exports = T200Crypto;