const T200Define = require('./T200Define.js');
const T200Resource = require('./T200Resource.js');
const T200Script = require('../script/T200Script.js');


class T200Source {
    constructor() {

    }

    static create_script(category, project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Define.create_script(category, project, source).then(async function(value){
                let script = new T200Script(value);
                resolve(script);
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    static create_case(category, project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_case(category, project, source);

            if(file){
                const CaseClass = require(file);

                if(CaseClass){
                    let CaseObj = new CaseClass();

                    if(CaseObj){
                        await CaseObj.create().then(function(){
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

    static create_web_page(project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_web_page(project, source);

            if(file){
                let WebClass = require(file);

                if(WebClass){
                    let WebObj = new WebClass(source);

                    if(WebObj){
                        WebObj.category = "web";
                        WebObj.project = project;
                        await WebObj.create().then(function(){
                            resolve(WebObj);
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

    static create_web_module(page, project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_web_module(project, source);

            if(file){
                let WebClass = require(file);

                if(WebClass){
                    let WebObj = new WebClass();

                    if(WebObj){
                        WebObj.category = "web";
                        WebObj.project = project;
                        await WebObj.create(page).then(function(){
                            resolve(WebObj);
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

}

module.exports = T200Source;