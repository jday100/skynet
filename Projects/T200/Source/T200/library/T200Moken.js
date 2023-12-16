const T200Error = require('./T200Error.js');
const T200Math = require('./T200Math.js');

class T200Moken {
    static _alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .\n";

    constructor() {

    }

    static mock_int(min, max) {
        return T200Math.random(min, max);
    }

    static mock_string(min, max) {
        let count = T200Math.random(min, max);
        let result = "";

        for(let i=0;i<count;i++){
            result += this.mock_letter();
        }

        return result;
    }

    static mock_letter() {
        let index = T200Math.random(0, 25);
        return this._alphabet[index];
    }

    static mock_chinese(min, max) {
        let count = T200Math.random(min, max);
        let result = "";

        for(let i=0;i<count;i++){
            result += String.fromCharCode(this.mock_int(13400, 40900));
        }

        return result;
    };
}

module.exports = T200Moken;