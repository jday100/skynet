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
            case 'password':
                T200Data.#build_password(field);
                break;
            case 'email':
                T200Data.#build_email(field);
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

        min = undefined == field.length.min ? 0 : Number(field.length.min);
        max = undefined == field.length.max ? 50 : Number(field.length.max);

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

    static #build_password(field) {
        let result = new Array();
        let min;
        let max;

        min = undefined == field.length.min ? 0 : Number(field.length.min);
        max = undefined == field.length.max ? 50 : Number(field.length.max);

        if(undefined == field.empty || field.empty == true){
            result.push('');

            let mid = min + (max - min) / 2;

            if(0 == min){

            }else{
                result.push(T200Moken.mock_string(min, min));
            }
            result.push(T200Moken.mock_string(mid, mid));
            if(0 == max){

            }else{
                result.push(T200Moken.mock_string(max, max));
            }
        }else{
            let mid = min + (max - min) / 2;

            if(0 == min){

            }else{
                result.push(T200Moken.mock_string(min, min));
            }
            result.push(T200Moken.mock_string(mid, mid));
            if(0 == max){

            }else{
                result.push(T200Moken.mock_string(max, max));
            }
        }

        field.values = result;
    }

    static #build_email(field) {
        let result = new Array();
        let value;
        let min = 1;
        let max = 50;


        if(undefined == field.empty || field.empty == true){
            result.push('');

            let mid = min + (max - min) / 2;

            if(0 == min){

            }else{
                value = T200Moken.mock_string(min, min);
                result.push(`${value}@${value}.com`);
            }
            value = T200Moken.mock_string(mid, mid);
            result.push(`${value}@${value}.net`);
            if(0 == max){

            }else{
                value = T200Moken.mock_string(max, max);
                result.push(`${value}@${value}.org`);
            }
        }else{
            let mid = min + (max - min) / 2;

            if(0 == min){

            }else{
                value = T200Moken.mock_string(min, min);
                result.push(`${value}@${value}.com`);
            }
            value = T200Moken.mock_string(mid, mid);
            result.push(`${value}@${value}.net`);
            if(0 == max){

            }else{
                value = T200Moken.mock_string(max, max);
                result.push(`${value}@${value}.org`);
            }
        }

        field.values = result;
    }
}

module.exports = T200Data;