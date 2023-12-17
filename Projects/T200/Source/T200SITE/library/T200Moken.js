const T200Error = require('./T200Error.js');
const T200Math = require('./T200Math.js');


class T200Moken {
    static _alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ .\n";

    constructor() {
        this._result = {};
    }

    clear() {
        if(undefined == this._result){

        }else{
            delete this._result;
        }
    }

    mock_unique_space(min, max) {
        let head;
        let tail;

        if(max >= min){
            head = min;
            tail = max;
        }else{
            head = max;
            tail = min;
        }

        if(head > 268435456)return undefined;

        if(undefined == this._result){
            this._result = new Array();

            for(let i=head;i<=tail;i++){
                this._result.push(i);
            }
        }

        let length = this._result.length - 1;
        let value = T200Math.random(0, length);
        let result = this._result[value];

        this._result[value] = this._result[length];
        this._result.pop();

        return result;
    }

    mock_unique_time(min, max) {
        let head;
        let tail;

        if(max >= min){
            head = min;
            tail = max;
        }else{
            head = max;
            tail = min;
        }

        if(head > 268435456)return undefined;

        let result;
        let flag;
        let count = 0;
        do{
            if(100 < count)break;

            result = T200Math.random(head, tail);

            flag = this._result[result];
            count++;
        }while(1 == flag);

        this._result[result] = 1;

        return result;
    }

    static mock_int(min, max) {
        let head;
        let tail;

        if(max >= min){
            head = min;
            tail = max;
        }else{
            head = max;
            tail = min;
        }

        return T200Math.random(head, tail);
    }

    static mock_letter() {
        let index = T200Math.random(0, 25);
        return this._alphabet[index];
    }

    static mock_string(min, max) {
        let count = T200Math.random(min, max);
        let result = "";

        for(let i=0;i<count;i++){
            result += this.mock_letter();
        }

        return result;
    }

    static mock_chinese(min, max) {
        let count = T200Math.random(min, max);
        let result = "";

        for(let i=0;i<count;i++){
            result += String.fromCharCode(this.mock_int(0x4e00, 0x9fa5));
        }

        return result;
    };
}

module.exports = T200Moken;