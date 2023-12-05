const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200SearchBiz = require('./T200SearchBiz.js');


class T200VisitorBiz extends T200SearchBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    register(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            model.flash_register_fields();
            model.flash_register_values();
            self.append(model.merge_register()).then(function(data){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    login(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            model.flash_login_fields();
            self.load(model.merge_login()).then(function(data){
                if(data){
                    resolve(data);
                }else{
                    reject();
                }
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    admin_login(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            model._fields = model.admin_login_fields();
            self.load(model.merge_admin_login()).then(function(data){
                if(data){
                    resolve(data);
                }else{
                    reject();
                }
            }, function(err){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200VisitorBiz;