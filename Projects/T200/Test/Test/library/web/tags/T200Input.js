const T200Tag = require('../T200Tag.js');


class T200Input extends T200Tag {
    constructor() {
        super();
    }

    run(browser, data) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await browser.locate(self.field.locate).then(async function(node){
                if(node){
                    await node.input(data).then(resolve, reject);
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

module.exports = T200Input;