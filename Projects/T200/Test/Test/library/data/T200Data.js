const T200Setup = require('../../project/T200Setup.js');
const { error } = require(T200Setup.external('./library/T200Lib.js'));
const T200Moken = require(T200Setup.external('./library/T200Moken.js'));


class T200Data {
    constructor() {

    }

    static build(field) {
        let result = true;
        switch(field.type){
            case undefined:
                break;
            case 'text':
                T200Data.#build_text(field);
                break;
            default:
                result = false;
        }

        return result;
    }

    static #build_text(field) {
        let result = new Array();
        let min;
        let max;

        min = undefined == field.min ? 0 : field.min;
        max = undefined == field.max ? 50 : field.max;

        if(undefined == field.empty || field.empty == true){
            result.push('');

            let mid = min + (max - min) / 2;

            if(0 == min){

            }else{
                result.push(T200Moken.mock_chinese(min, min));
            }
            result.push(T200Moken.mock_chinese(mid, mid));
            if(0 == max){

            }else{
                result.push(T200Moken.mock_chinese(max, max));
            }
        }else{
            let mid = min + (max - min) / 2;

            if(0 == min){

            }else{
                result.push(T200Moken.mock_chinese(min, min));
            }
            result.push(T200Moken.mock_chinese(mid, mid));
            if(0 == max){

            }else{
                result.push(T200Moken.mock_chinese(max, max));
            }
        }

        field.values = result;
    }
}

module.exports = T200Data;