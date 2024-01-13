const T200Resource = require('./T200Resource.js');
const T200Define = require('./T200Define.js');

const T200Setup = require('../project/T200Setup.js');
const { error } = require(T200Setup.external('./library/T200Lib.js'));
const T200Moken = require(T200Setup.external('./library/T200Moken.js'));


class T200Data {
    constructor() {

    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_test_data("data");

            if(file){
                await T200Define.create(file).then(function(obj){
                    self.data = obj;
                    resolve();
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }

    static build(field, values) {
        let result = true;
        switch(field.type){
            case undefined:
                break;
            case 'text':
                T200Data.#build_text(field, values);
                break;
            default:
                result = false;
        }

        return result;
    }

    static #build_text(field, values) {
        let min = 1;
        let max = 50;

        let result = T200Moken.mock_chinese(min, max);

        values[field.name] = result;
    }
}

module.exports = T200Data;