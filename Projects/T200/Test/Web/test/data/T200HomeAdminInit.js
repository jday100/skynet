const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');
const T200Admin = require('../../project/models/T200Admin.js');


class T200HomeAdminInit {
    constructor() {

    }

    execute(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let admin = new T200Admin();
            let result = false;

            let moken = new T200Moken();

            for(let i=0;i<1000;i++){
                let user_id = moken.mock_unique(1, 1000);
                let status = T200Moken.mock_int(0, 1);
                let remark = T200Moken.mock_string(6, 255);
                let permission = T200Moken.mock_string(6, 255);

                admin.user_id = user_id;
                admin.status = status;
                admin.remark = remark;
                admin.permission = permission;

                admin.flash_append_fields();
                admin.flash_append_values();

                await client.execute(admin.merge_insert()).then(function(){
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

module.exports = T200HomeAdminInit;