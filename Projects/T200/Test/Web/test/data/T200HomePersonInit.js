const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');
const T200Person = require('../../project/models/T200Person.js');


class T200HomePersonInit {
    constructor() {

    }

    execute(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let person = new T200Person();
            let result = false;

            for(let i=0;i<1000;i++){
                let status = T200Moken.mock_int(0, 1);
                let username = T200Moken.mock_string(6, 50);
                let password = T200Moken.mock_string(6, 100);
                let nickname = T200Moken.mock_string(6, 100);
                let email = T200Moken.mock_string(6, 100);
                let gender = T200Moken.mock_int(0, 2);
                let year = T200Moken.mock_int(1920, 2023);
                let month = T200Moken.mock_int(1, 12);
                let day = T200Moken.mock_int(1, 31);
                let intro = T200Moken.mock_string(6, 255);
                let flag = T200Moken.mock_int(0, 1);

                person.status = status;
                person.username = username;
                person.password = password;
                person.nickname = nickname;
                person.email = email;
                person.gender = gender;
                person.year = year;
                person.month = month;
                person.day = day;
                person.intro = intro;
                person.flag = flag;

                person.flash_append_fields();
                person.flash_append_values();

                await client.execute(person.merge_insert()).then(function(){
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

module.exports = T200HomePersonInit;