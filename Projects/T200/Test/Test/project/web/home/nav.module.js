const T200Module = require('../../../library/web/T200Module.js');


class T200NavModule extends T200Module {
    constructor() {
        super();
        this.name = "nav";
    }

    run(browser, options){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let form = self.values[0];
            await form.run(browser, options).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200NavModule;