const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200ForumBiz = require('./T200ForumBiz.js');


class T200UserBiz extends T200ForumBiz {
    constructor() {
        super();
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

    login(user) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.check().then(function(){
                self.store.connected().then(function(){
                    self.store.query(user.merge_login()).then(function(){
                        self.store.execute(user.merge_login_update()).then(function(){
                            
                        }, function(){

                        });
                    }, function(){

                    });
                }, function(){

                });
            }, function(){

            });
        });

        return promise;
    }

}

module.exports = T200UserBiz;