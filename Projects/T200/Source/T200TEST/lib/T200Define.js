const T200Setup = require('../project/T200Setup.js');

const T200File = require(T200Setup.external('./library/fs/T200File.js'));


class T200Define {
    constructor() {

    }

    static create(file) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            T200File.load(file).then(function(data){
                resolve(data);
            }, function(){
                reject();
            })
        });

        return promise;
    }
}

module.exports = T200Define;