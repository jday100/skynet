const T200Resource = require('../T200Resource.js');
const T200Define = require('../T200Define.js');



class T200Module {
    constructor(page) {
        this.page = page;
        this.values = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.#create_define(self.name).then(function(obj){
                self.page.create_fields(obj).then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }, function(err){
                reject();
            });
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
                    resolve(obj);
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

module.exports = T200Module;