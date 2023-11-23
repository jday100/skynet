const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200AdminBiz = require('../../library/web/biz/T200AdminBiz.js');
const T200HomeStore = require('../store/T200HomeStore.js');


class T200HomeAdminBiz extends T200AdminBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
        this.store = new T200HomeStore();
    }

    
    add(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = false;
            if(self.check()){
                return self.store.connect().then(function(){
                    model._fields = model.fields();
                    model._values = model.values();
                    return self.store.insert(model.merge_insert()).then(function(){
                        result = true;
                    }, function(){

                    }).finally(function(){
                        return self.store.disconnect().then(function(){

                        }, function(){

                        });
                    });
                }, function(){

                }).finally(function(){
                    if(result){
                        resolve();
                    }else{
                        reject();
                    }
                });
            }else{
                reject();
            }
        });

        return promise;
    }
}

module.exports = T200HomeAdminBiz;