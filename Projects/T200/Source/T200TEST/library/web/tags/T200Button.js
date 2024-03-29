const T200Input = require('./T200Input.js');


class T200Button extends T200Input {
    constructor() {
        super();
    }

    create(field) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.field = field;
            self.tag = field;
            await  self.create_tag().then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    run(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await browser.locate(self.field.locate).then(async function(node){
                if(node){
                    await node.click().then(function(){
                        global.final.entry_success(self.project, self.page, self.tag.name);
                        resolve();
                    }, function(err){
                        global.final.entry_failure(self.project, self.page, self.tag.name);
                        reject();
                    });
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