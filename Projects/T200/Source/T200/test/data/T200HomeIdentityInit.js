const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');
const T200Identity = require('../../project/models/T200Identity.js');


class T200HomeIdentityInit {
    constructor() {

    }

    execute(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let identity = new T200Identity();
            let result = false;

            for(let i=0;i<1000;i++){
                let user_id = T200Moken.mock_int(1, 1000);
                let status = T200Moken.mock_int(0, 1);
                let nickname = T200Moken.mock_string(6, 100);
                let intro = T200Moken.mock_string(6, 255);
                let flag = T200Moken.mock_int(0, 1);

                identity.user_id = user_id;
                identity.status = status;
                identity.nickname = nickname;
                identity.intro = intro;
                identity.flag = flag;

                identity.flash_append_fields();
                identity.flash_append_values();

                await client.execute(identity.merge_insert()).then(function(){
                    result = true;
                }, function(){
                    result = false;
                });

                if(!result)break;
            }

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }
}

module.exports = T200HomeIdentityInit;