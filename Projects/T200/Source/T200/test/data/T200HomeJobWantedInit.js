const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');
const T200Job = require('../../project/models/T200Job.js');


class T200HomeJobWantedInit {
    constructor() {

    }

    execute(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let job = new T200Job();
            let result = false;

            for(let i=0;i<1000;i++){
                let user_id = T200Moken.mock_int(1, 1000);
                let status = T200Moken.mock_int(0, 1);
                let parent_type = T200Moken.mock_int(0, 1);
                let parent_id = T200Moken.mock_int(1, 100);
                let type_full = T200Moken.mock_int(0, 1);
                let type_part = T200Moken.mock_int(0, 1);
                let title = T200Moken.mock_chinese(6, 255);
                let content = T200Moken.mock_chinese(6, 1024);

                job.user_id = user_id;
                job.status = status;
                job.parent_type = parent_type;
                job.parent_id = parent_id;
                job.type_full = type_full;
                job.type_part = type_part;
                job.title = title;
                job.content = content;

                job._table = "job_wanted";
                job.flash_append_fields();
                job.flash_append_values();

                await client.execute(job.merge_insert()).then(function(){
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

module.exports = T200HomeJobWantedInit;