const T200Input = require('./T200Input.js');


class T200Button extends T200Input {
    constructor() {
        super();
    }

    create(field) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.field = field;
            resolve();
        });

        return promise;
    }

    run(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await browser.locate(self.field.locate).then(async function(node){
                if(node){
                    await node.click().then(resolve, reject);
                }else{
                    reject();
                }
            },function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200Button;