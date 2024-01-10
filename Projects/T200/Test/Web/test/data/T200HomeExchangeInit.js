const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');
const T200Exchange = require('../../project/models/T200Exchange.js');


class T200HomeExchangeInit {
    constructor() {

    }

    execute(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let exchange = new T200Exchange();
            let result = false;

            for(let i=0;i<1000;i++){
                let user_id = T200Moken.mock_int(1, 1000);
                let identity_id = T200Moken.mock_int(0, 1000);
                let status = T200Moken.mock_int(0, 1);
                let parent_type = T200Moken.mock_int(0, 1);
                let parent_id = T200Moken.mock_int(1, 100);
                let title = T200Moken.mock_chinese(6, 255);
                let content = T200Moken.mock_chinese(6, 1024);

                if(0 == parent_type){
                    parent_id = i + 1;
                }

                exchange.user_id = user_id;
                exchange.identity_id = identity_id;
                exchange.status = status;
                exchange.parent_type = parent_type;
                exchange.parent_id = parent_id;
                exchange.title = title;
                exchange.content = content;

                exchange.flash_append_fields();
                exchange.flash_append_values();

                await client.execute(exchange.merge_insert()).then(function(){
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

module.exports = T200HomeExchangeInit;