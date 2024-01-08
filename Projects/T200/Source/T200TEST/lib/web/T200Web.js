const T200Source = require('../T200Source.js');
const T200Resource = require('../T200Resource.js');


class T200Web {
    constructor(name) {
        this.name = name;
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = T200Resource.merge_test_unit(self.name);

            if(file){
                T200Source.create(file).then(function(obj){
                    self.object = obj;
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

    run(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.object){
                self.object.run(browser).then(function(){
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
}

module.exports = T200Web;