const T200Resource = require('../../lib/T200Resource.js');
const T200Define = require('../../lib/T200Define.js');
const T200Page = require('../../lib/web/T200Page.js');


class T200LoginWeb {
    constructor() {
        this.objects = [
            "person"
        ];

        this.modules = [
            "nav"
        ];

        this.values = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            for(let obj of self.objects){
                await self.#create_define(obj).then(function(){
                    
                }, function(){
                    result = false;
                });

                if(!result)break;
            }

            if(result){
                await self.#create_page().then(function(){
                    resolve();
                }, function(){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }

    #create_define(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = T200Resource.merge_object_define(name);

            if(file){
                T200Define.create(file).then(function(obj){
                    self.values.push(obj);
                    resolve();
                }, function(){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }

    #create_page() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let page = new T200Page();

            page.create(self).then(function(){
                self.page = page;
                resolve(page);
            }, function(){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200LoginWeb;