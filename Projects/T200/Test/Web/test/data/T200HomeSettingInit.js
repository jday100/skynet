const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');
const T200Setting = require('../../project/models/T200Setting.js');


class T200HomeSettingInit {
    constructor() {

    }

    execute(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let setting = new T200Setting();
            let result = false;
            let moken = new T200Moken();


            for(let i=0;i<1000;i++){
                let setting_id = moken.mock_unique(1000000, 9000000);
                let status = T200Moken.mock_int(0, 1);
                let name = T200Moken.mock_string(6, 255);
                let content = T200Moken.mock_string(6, 255);


                setting.setting_id = setting_id;
                setting.status = status;                
                setting.name = name;
                setting.content = content;

                setting.flash_append_fields();
                setting.flash_append_values();

                await client.execute(setting.merge_insert()).then(function(){
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

module.exports = T200HomeSettingInit;