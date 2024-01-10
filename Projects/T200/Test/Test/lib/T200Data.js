const T200Resource = require('./T200Resource.js');
const T200Define = require('./T200Define.js');


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
}

module.exports = T200Data;