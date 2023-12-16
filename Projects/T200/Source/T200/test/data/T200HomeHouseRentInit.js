const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');
const T200House = require('../../project/models/T200House.js');


class T200HomeHouseRentInit {
    constructor() {

    }

    execute(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let notice = new T200Notice();
            let result = false;

            for(let i=0;i<1000;i++){
                let user_id = T200Moken.mock_int(1, 100);
                let status = T200Moken.mock_int(0, 1);
                let title = T200Moken.mock_string(6, 255);
                let content = T200Moken.mock_string(6, 1024);

                notice.user_id = user_id;
                notice.status = status;
                notice.title = title;
                notice.content = content;

                notice.flash_append_fields();
                notice.flash_append_values();

                await client.execute(notice.merge_insert()).then(function(){
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

module.exports = T200HomeHouseRentInit;