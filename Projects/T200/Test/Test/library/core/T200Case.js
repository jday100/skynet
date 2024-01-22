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
}

module.exports = T200Case;