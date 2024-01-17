const T200Define = require('../T200Define.js');


class T200Module {
    constructor() {

    }

    create(page) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.parent = page;
            await T200Define.create_web_module(self.project, self.name).then(function(value){
                self.define_value = value;
            }, function(err){

            }).then(function(value){
                return self.parent.create_fields(self);
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