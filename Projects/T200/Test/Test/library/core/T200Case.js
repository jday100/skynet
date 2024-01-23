const T200Source = require('./T200Source.js');


class T200Case {
    constructor() {

    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Source.create_web_page(self.project, self.name).then(function(value){
                self.page = value;
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    run(browser){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.page.run(browser).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    form(browser){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.page.form(browser).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200Case;