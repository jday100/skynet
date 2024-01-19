const T200Input = require('./T200Input.js');


class T200Select extends T200Input {
    constructor() {
        super();
    }

    run(browser, data) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await browser.locate(self.field.locate).then(async function(node){
                if(node){
                    await node.select(data).then(resolve, reject);
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

module.exports = T200Select;