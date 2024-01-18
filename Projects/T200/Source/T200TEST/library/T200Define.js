const T200Resource = require('./T200Resource.js');
const T200Setup = require('../project/T200Setup.js');
const T200File = require(T200Setup.external('./library/fs/T200File.js'));


class T200Define {
    constructor() {

    }

    static load_data(name) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_data(name);

            if(file){
                await T200File.load(file).then(function(data){
                    let value = data.toString();
                    let JsonObj = JSON.parse(value);

                    if(JsonObj){
                        resolve(JsonObj);
                    }else{
                        reject();
                    }
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }

    static create_web_page(name) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_object_define(name);

            if(file){
                await T200File.load(file).then(function(data){
                    let value = data.toString();
                    let JsonObj = JSON.parse(value);

                    if(JsonObj){
                        resolve(JsonObj);
                    }else{
                        reject();
                    }
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }

    static create_web_module(project, name) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_web_define(project, name);

            if(file){
                await T200File.load(file).then(function(data){
                    let value = data.toString();
                    let JsonObj = JSON.parse(value);

                    if(JsonObj){
                        resolve(JsonObj);
                    }else{
                        reject();
                    }
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }

    static create_web_flow(name) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let file = T200Resource.merge_web_flow(name);

            if(file){
                await T200File.load(file).then(function(data){
                    let value = data.toString();
                    let JsonObj = JSON.parse(value);

                    if(JsonObj){
                        resolve(JsonObj);
                    }else{
                        reject();
                    }
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }
}

module.exports = T200Define;