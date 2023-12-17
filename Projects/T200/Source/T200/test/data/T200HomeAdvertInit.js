const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');
const T200Advert = require('../../project/models/T200Advert.js');


class T200HomeAdvertInit {
    constructor() {

    }

    execute(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let advert = new T200Advert();
            let result = false;

            for(let i=0;i<1000;i++){
                let status = T200Moken.mock_int(0, 1);
                let name = T200Moken.mock_string(6, 255);
                let content = T200Moken.mock_string(6, 255);

                advert.status = status;
                advert.name = name;
                advert.content = content;

                advert.flash_append_fields();
                advert.flash_append_values();

                await client.execute(advert.merge_insert()).then(function(){
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

module.exports = T200HomeAdvertInit;