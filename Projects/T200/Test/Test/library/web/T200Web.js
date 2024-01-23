const T200Resource = require('../core/T200Resource.js');


class T200Web {
    constructor() {

    }

    create(project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_case("web", project, source);

            if(file){
                const CaseClass = require(file);

                if(CaseClass){
                    let CaseObj = new CaseClass();

                    if(CaseObj){
                        CaseObj.category = "web";
                        CaseObj.project = project;
                        await CaseObj.create().then(function(){
                            self.value = CaseObj;
                            resolve(CaseObj);
                        }, function(err){
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

    run(browser){
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.value.run(browser).then(function(){
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
            await self.value.form(browser).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200Web;