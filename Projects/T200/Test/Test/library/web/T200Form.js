const T200Module = require('./T200Module.js');


class T200Form extends T200Module {
    constructor() {
        super();
    }

    
    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Define.create_module(self.name).then(function(){

            }, function(err){

            }).then(function(){

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

module.exports = T200Form;