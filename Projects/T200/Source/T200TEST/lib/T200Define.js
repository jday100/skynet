const T200Setup = require('../project/T200Setup.js');

const T200File = require(T200Setup.external('./library/fs/T200File.js'));


class T200Define {
    constructor() {

    }

    static create(file) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let name = "";
            let flag = false;
            for(let letter of file){
                if(false == flag){
                    name += letter.toUpperCase();
                    flag = true;
                }else{
                    name += letter;
                }
            }
            let real = `./project/define/T200${name}.txt`;

            T200File.load(real).then(function(data){
                resolve(data);
            }, function(){
                reject();
            })
        });

        return promise;
    }
}

module.exports = T200Define;