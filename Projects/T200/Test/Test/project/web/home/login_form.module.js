const T200Module = require('../../../library/web/T200Module.js');


class T200LoginFormModule extends T200Module {
    constructor() {
        super();
        this.name = "login_form";
    }

    run(browser){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let form = self.values[0];
            await form.run(browser).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200LoginFormModule;