const T200Module = require('../../../library/web/T200Module.js');


class T200RegisterFormModule extends T200Module {
    constructor() {
        super();
        this.name = "register_form";
    }

    run(browser){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let form;

            for(let module of self.values){
                if("register_form" == module.name){
                    form = module;
                    break;
                }
            }

            if(undefined == form){
                reject();
            }else{
                await form.run(browser).then(resolve, reject);
            }
        });

        return promise;
    }
}

module.exports = T200RegisterFormModule;