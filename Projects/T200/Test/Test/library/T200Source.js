const T200Resource = require('./T200Resource.js');


class T200Source {
    constructor() {

    }

    static create_web(project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_web_unit(project, source);

            if(file){
                let WebClass = require(file);

                if(WebClass){
                    let WebObj = new WebClass();

                    if(WebObj){
                        WebObj.project = project;
                        await WebObj.create().then(function(){
                            resolve();
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
                    let WebObj = new WebClass();

                    if(WebObj){
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

    static create_web_module(project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_web_module(project, source);

            if(file){
                let WebClass = require(file);

                if(WebClass){
                    let WebObj = new WebClass();

                    if(WebObj){
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

    static create_flow_parser(name) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_flow_parser(name);

            if(file){
                let WebClass = require(file);

                if(WebClass){
                    let WebObj = new WebClass();

                    if(WebObj){
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
}

module.exports = T200Source;
