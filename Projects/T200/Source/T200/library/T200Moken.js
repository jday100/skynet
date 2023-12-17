const T200Error = require('./T200Error.js');
const T200Math = require('./T200Math.js');

class T200Moken {
    static _alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .\n";

    constructor() {
    }

    clear() {

    }

    mock_unique(min, max) {
        if(undefined == this._result){
            this._result = new Array();

            for(let i=min;i<=max;i++){
                this._result.push(i);
            }
        }

        let length = this._result.length;

        let value = T200Math.random(0, length-1);
        let result = this._result.at(value);
        this._result[value] = this._result[length - 1];
        this._result.pop();

        return result;
    }

    mock_unique1(min, max) {
        let value;
        let flag;
        let count = 0;
        do{
            if(10 < count)break;

            value = T200Math.random(min, max);

            flag = this._result[value];
            count++;
        }while(1 == flag);

        this._result[value] = 1;
        return value;
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