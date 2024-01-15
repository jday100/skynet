const T200Define = require('../T200Define.js');
const T200Source = require('../T200Source.js');


class T200Page {
    constructor() {
        this.define_values = new Array();
        this.module_values = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.#create_defines().then(function(){

            }, function(err){

            }).then(async function(){
                return await self.#create_modules();
            }, function(err){

            }).then(async function(){
                return await self.#create_page();
            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_defines() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let name of self.defines){
                await T200Define.create_page(name).then(function(){

                }, function(err){
                    result = false;
                });
            }

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }

    #create_modules() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let name of self.modules){
                await T200Source.create_web_module(self.project, name).then(function(value){
                    self.module_values.push(value);
                }, function(err){
                    result = false;
                });
            }

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }

    #create_page() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    create_fields() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    create_field() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    test_flow(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }
    
    test_unit(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }
}

module.exports = T200Page;