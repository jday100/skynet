const T200Resource = require('../../../lib/T200Resource.js');
const T200Define = require('../../../lib/T200Define.js');


class T200LoginModule {
    constructor() {
        this.name = "login_form";
        this.values = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.#create_define(self.name).then(resolve, reject);
        });

        return promise;
    }

    #create_define(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = T200Resource.merge_web_define(name);

            if(file){
                T200Define.create(file).then(function(obj){
                    self.values.push(obj);
                    resolve();
                }, function(){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }
}

module.exports = T200LoginModule;