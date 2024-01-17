const T200Tag = require('../T200Tag.js');
const T200Data = require('../../data/T200Data.js');


class T200Input extends T200Tag {
    constructor() {
        super();
    }

    create(field) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.field = field;

            let data = {};

            data = field.value;

            data.type = field.type;
            //data.empty = field.empty;
            self.data = data;

            await self.create_tag().then(function(){

            }, function(err){

            }).then(function(){
                return self.#build_data(data);
            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });            
        });

        return promise;
    }

    run(browser, data) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await browser.locate(self.field.locate).then(async function(node){
                if(node){
                    await node.input(data).then(resolve, reject);
                }else{
                    reject();
                }
            },function(err){
                reject();
            });
        });

        return promise;
    }

    #build_data(data) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(T200Data.build(data)){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }
}

module.exports = T200Input;