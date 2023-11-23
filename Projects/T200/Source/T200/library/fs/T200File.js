const T200Error = require('../T200Error.js');
const fs = require('fs');


class T200File {
    constructor() {

    }

    static exists(file) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            fs.access(file, fs.constants.F_OK, function(err){
                if(err){
                    reject(T200Error.build());
                }else{
                    resolve();
                }
            });
        });

        return promise;
    }

    static load(file) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            fs.readFile(file, function(err, data){
                if(err){
                    reject(T200Error.build());
                }else{
                    resolve(data);
                }
            });
        });

        return promise;
    }
}

module.exports = T200File;