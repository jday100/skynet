const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');
const T200Invitation = require('../../project/models/T200Invitation.js');


class T200HomeInvitationInit {
    constructor() {

    }

    execute(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let invitation = new T200Invitation();
            let result = false;

            for(let i=0;i<1000;i++){
                let user_id = T200Moken.mock_int(0, 1000);
                let status = T200Moken.mock_int(0, 1);
                let invite = T200Moken.mock_int(111111111111, 999999999999);

                invitation.user_id = user_id;
                invitation.status = status;
                invitation.invite = invite;

                invitation.flash_append_fields();
                invitation.flash_append_values();

                await client.execute(invitation.merge_insert()).then(function(){
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

module.exports = T200HomeInvitationInit;