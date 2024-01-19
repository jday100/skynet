const T200Tag = require('../T200Tag.js');


class T200Menu extends T200Tag {
    constructor() {
        super();
    }

    create(tag) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.tag = tag;
            self.field = tag;

            let result = true;

            await  self.create_tag().then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    run2(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.browser = browser;
            await self.tag.run(browser).then(function(){
                global.final.entry_success(self.project, self.page, self.tag.name);
            }, function(err){
                global.final.entry_failure(self.project, self.page, self.tag.name);
            }).then(function(){
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

module.exports = T200Menu;