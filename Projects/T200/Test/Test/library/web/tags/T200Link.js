const T200Tag = require('../T200Tag.js');


class T200Link extends T200Tag {
    constructor() {
        super();
    }

    create(tag) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.tag = tag;

            let result = true;
            let name = tag.type;

            switch(tag.target){
                case 'blank':
                    name = "link_blank";
                    break;
            }

            await self.create_flow(name).then(function(){

            }, function(err){

            }).then(function(){
                return self.create_tag();
            }, function(err){

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
            self.browser = browser;
            await self.flow.run(browser, self.tag).then(function(){
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
}

module.exports = T200Link;