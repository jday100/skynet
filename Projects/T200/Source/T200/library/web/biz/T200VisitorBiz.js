const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200SearchBiz = require('./T200SearchBiz.js');


class T200VisitorBiz extends T200SearchBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    register(user) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                if(self.store.is_connected()){
                    return self.register_done(user).then(resolve, reject);
                }else{
                    return self.store.connect().then(function(){
                        return self.register_done(user).then(resolve, reject);
                    }, function(err){
                        reject();
                    }).catch(function(err){
                        console.log(err);
                        reject();
                    });
                }
            }else{
                reject();
            }
        });

        return promise;
    }

    register_done(user) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.store.execute(user.merge_register()).then(function(data){
                let result = typeof(data);
                console.log(result)
                if(data && 0 == data.warningStatus){
                    resolve();
                }else{
                    reject();
                }            
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    login(user) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                if(self.store.is_connected()){
                    return self.login_done(user).then(resolve, reject);
                }else{
                    return self.store.connect().then(function(){
                        return self.login_done(user).then(resolve, reject);
                    }, function(err){
                        reject();
                    }).catch(function(err){
                        console.log(err);
                        reject();
                    });
                }
            }else{
                reject();
            }
        });

        return promise;
    }

    login_done(user) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.store.query(user.merge_login()).then(function(data){
                if(data && 1 == data.length){
                    return self.store.execute(user.merge_login_update()).then(function(){
                        resolve(data);
                    }, function(err){
                        reject();
                    });
                }else{
                    reject();
                }            
            }, function(err){
                reject();
            });
        });
        
        return promise;
    }


    admin_login(user) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                if(self.store.is_connected()){
                    return self.login_done(user).then(resolve, reject);
                }else{
                    return self.store.connect().then(function(){
                        return self.login_done(user).then(resolve, reject);
                    }, function(err){
                        reject();
                    }).catch(function(err){
                        console.log(err);
                        reject();
                    });
                }
            }else{
                reject();
            }
        });

        return promise;
    }
}

module.exports = T200VisitorBiz;