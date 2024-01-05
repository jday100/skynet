const T200Object = require('./T200Object.js');
const T200Resource = require('./T200Resource.js');


class T200Source {
    constructor(name) {
        this.name = name;
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let CaseSource = T200Resource.merge_case(self.name);

            if(CaseSource){
                const CaseClass = require(CaseSource);

                if(CaseClass){
                    let CaseObj = new CaseClass();

                    if(CaseObj){
                        CaseObj.create().then(function(){
                            self.object = CaseObj;
                            self.methods = T200Object.methods(CaseObj);

                            resolve(self.methods);
                        }, function(){
                            reject();
                        });
                    }else{
                        reject();
                    }
                }else{
                    reject();
                }
            }else{
                reject();
            }
        });

        return promise;
    }

    run(browser, method) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.object[method](browser).then(resolve, reject);
        });

        return promise;
    }
}

module.exports = T200Source;