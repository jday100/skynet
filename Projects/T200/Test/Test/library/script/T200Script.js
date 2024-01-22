const T200Resource = require('../core/T200Resource.js');
const T200Setup = require('../../config/T200Setup.js');
const T200File = require(T200Setup.external('./library/fs/T200File.js'));

const T200ScriptParser = require('./T200ScriptParser.js');


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
        let promise = new Promise(async function(resolve, reject){
            let script = new T200ScriptParser(self.script);
            let name = undefined == method ? "all" : method;
            script.browser = self.browser;
            script.category = self.category;
            script.project = self.project;
            script.type = self.type;
            await script.run(name).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });
        
        return promise;
    }
}

module.exports = T200Script;