const T200Resource = require('./T200Resource.js');
const T200Setup = require('../../config/T200Setup.js');
const T200File = require(T200Setup.external('./library/fs/T200File.js'));


class T200Define {
    constructor() {

    }

    static create_script(category, project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_file(category, project, source);

            if(file){
                await T200File.load(file).then(function(data){
                    let value = data.toString();
                    let JsonObj = JSON.parse(value);

                    if(JsonObj){
                        resolve(JsonObj);
                    }else{
                        reject();
                    }
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

module.exports = T200Define;