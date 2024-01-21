const T200Define = require('./T200Define.js');
const T200Script = require('../script/T200Script.js');


class T200Source {
    constructor() {

    }

    static create_script(category, project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Define.create_script(category, project, source).then(async function(value){
                let script = new T200Script(value);
                resolve(script);
            }, function(err){
                reject();
            });
        });

        return promise;
    }


}

module.exports = T200Source;