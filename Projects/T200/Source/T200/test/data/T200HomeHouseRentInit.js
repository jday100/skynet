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
            let house = new T200House();
            let result = false;

            for(let i=0;i<1000;i++){
                let user_id = T200Moken.mock_int(1, 1000);
                let identity_id = T200Moken.mock_int(0, 1000);
                let status = T200Moken.mock_int(0, 1);
                let parent_type = T200Moken.mock_int(0, 1);
                let parent_id = T200Moken.mock_int(1, 100);
                let type_long = T200Moken.mock_int(0, 1);
                let type_short = T200Moken.mock_int(0, 1);
                let title = T200Moken.mock_chinese(6, 255);
                let content = T200Moken.mock_chinese(6, 1024);

                if(0 == parent_type){
                    parent_id = i + 1;
                }

                house.user_id = user_id;
                house.identity_id = identity_id;
                house.status = status;
                house.parent_type = parent_type;
                house.parent_id = parent_id;
                house.type_long = type_long;
                house.type_short = type_short;
                house.title = title;
                house.content = content;

                house._table = "house_rent";
                house.flash_append_fields();
                house.flash_append_values();

                await client.execute(house.merge_insert()).then(function(){
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