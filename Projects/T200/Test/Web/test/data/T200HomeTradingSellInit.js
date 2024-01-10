const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');
const T200Trading = require('../../project/models/T200Trading.js');


class T200HomeTradingSellInit {
    constructor() {

    }

    execute(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let trading = new T200Trading();
            let result = false;

            for(let i=0;i<1000;i++){
                let user_id = T200Moken.mock_int(1, 1000);
                let identity_id = T200Moken.mock_int(1, 1000);
                let status = T200Moken.mock_int(0, 1);
                let parent_type = T200Moken.mock_int(0, 1);
                let parent_id = T200Moken.mock_int(1, 100);
                let title = T200Moken.mock_chinese(6, 255);
                let content = T200Moken.mock_chinese(6, 1024);

                if(0 == parent_type){
                    parent_id = i + 1;
                }

                trading.user_id = user_id;
                trading.identity_id = identity_id;
                trading.status = status;
                trading.parent_type = parent_type;
                trading.parent_id = parent_id;
                trading.title = title;
                trading.content = content;

                trading._table = "trading_sell";
                trading.flash_append_fields();
                trading.flash_append_values();

                await client.execute(trading.merge_insert()).then(function(){
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

module.exports = T200HomeTradingSellInit;