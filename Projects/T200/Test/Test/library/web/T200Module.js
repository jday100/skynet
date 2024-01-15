const T200Define = require('../T200Define.js');


class T200Module {
    constructor() {

    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Define.create_web_module(self.project, self.name).then(function(value){
                self.define_value = value;
            }, function(err){

            }).then(function(value){

            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200Module;