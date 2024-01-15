const T200Tag = require('../T200Tag.js');


class T200Link extends T200Tag {
    constructor() {
        super();
    }

    create() {

    }

    run(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.browser = browser;
            self.flow.run(browser, self.tag).then(function(){

            }, function(err){

            }).then(function(){

            }, function(err){

            });
        });

        return promise;
    }
}

module.exports = T200Link;