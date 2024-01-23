const T200Tag = require('../T200Tag.js');


class T200Button extends T200Tag {
    constructor() {
        super();
    }

    click(browser) {
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