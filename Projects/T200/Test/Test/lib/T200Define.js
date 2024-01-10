const T200Setup = require('../project/T200Setup.js');
const T200File = require(T200Setup.external('./library/fs/T200File.js'));


class T200Define {
    constructor() {

    }

    static create(file) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            T200File.load(file).then(function(data){
                let value = data.toString();
                let obj = JSON.parse(value);

                if(obj){
                    resolve(obj);
                }else{
                    reject();
                }
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200Define;