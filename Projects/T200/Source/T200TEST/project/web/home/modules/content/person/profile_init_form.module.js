const T200Module = require('../../../../../../library/web/T200Module.js');


class T200ProfileInitFormModule extends T200Module {
    constructor() {
        super();
        this.name = "content/person/profile_init_form";
    }

    verify(value) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = value.indexOf("success");

            if(0 <= result){
                resolve();
                return;
            }

            result = value.indexOf("failure");
            if(0 <= result){
                reject();
                return;
            }

            reject();
        });

        return promise;
    }
}

module.exports = T200ProfileInitFormModule;