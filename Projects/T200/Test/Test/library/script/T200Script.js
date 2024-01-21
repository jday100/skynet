const T200Resource = require('../core/T200Resource.js');
const T200Setup = require('../../config/T200Setup.js');
const T200File = require(T200Setup.external('./library/fs/T200File.js'));


class T200Script {
    constructor(script) {
        this.script = script;
    }

    static create(category, project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_file(category, project, source);

            if(file){
                let script = {};

                script.all = new Array();
                script.all.push("step1");
                script.all.push("step2");

                let result = JSON.stringify(script);

                await T200File.save(file, result).then(function(){
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

    run(method) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let flow = self.script[method];

            if(flow){

            }else{
                reject();
            }
        });
        
        return promise;
    }
}

module.exports = T200Script;