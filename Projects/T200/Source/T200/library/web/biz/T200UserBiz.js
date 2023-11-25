const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200ForumBiz = require('./T200ForumBiz.js');


class T200UserBiz extends T200ForumBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    verify_logined(cookie, session) {
        let sid = cookie.get("sid");

        if(sid && 0 < sid._value){
            let user_id = session.get("userid");
            if(user_id && 0 < user_id){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    }

    
    get_one(model, value) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                if(self.store.is_connected()){
                    return self.get_one_done(model, value).then(resolve, reject);
                }else{
                    return self.store.connect().then(function(){
                        return self.get_one_done(model, value).then(resolve, reject);
                    }, function(err){
                        reject();
                    }).catch(function(err){
                        console.log(err);
                        reject();
                    }).finally(function(){
                        self.store.disconnect().then(function(){

                        }, function(){

                        });
                    });
                }
            }else{
                reject();
            }
        });

        return promise;
    }

    get_one_done(model, value) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.store.query(model.merge_select_by_key(value)).then(function(data){
                if(data && 1 == data.length){
                    resolve(data[0]);
                }else{
                    reject();
                }            
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    
    modify(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                if(self.store.is_connected()){
                    return self.modify_done(sql).then(resolve, reject);
                }else{
                    return self.store.connect().then(function(){
                        return self.modify_done(sql).then(resolve, reject);
                    }, function(err){
                        reject();
                    }).catch(function(err){
                        console.log(err);
                        reject();
                    }).finally(function(){
                        self.store.disconnect().then(function(){

                        }, function(){

                        });
                    });
                }
            }else{
                reject();
            }
        });

        return promise;
    }

    modify_done(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.store.execute(sql).then(function(data){
                if(data && 0 == data.warningStatus){
                    resolve(true);
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

module.exports = T200UserBiz;