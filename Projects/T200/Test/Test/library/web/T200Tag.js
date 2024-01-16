const T200Flow = require('../flow/T200Flow.js');


class T200Tag {
    constructor() {

    }

    
    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            
        });

        return promise;
    }

    create_tag() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            global.final.append_entry(self.project, self.page, self.name);
            resolve();
        });

        return promise;
    }

    create_flow(name) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let flow = new T200Flow(name);

            await flow.create().then(function(){
                self.flow = flow;
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200Tag;