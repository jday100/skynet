const T200Resource = require('../../lib/T200Resource.js');
const T200Define = require('../../lib/T200Define.js');
const T200Page = require('../../lib/web/T200Page.js');


class T200LoginWeb {
    constructor() {
        this.objects = [
            'person'
        ];

        this.modules = [
            'nav.module.js'
        ];

        this.object_values = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            for(let obj of self.objects){
                self.#create_define(obj).then(function(){

                }, function(){

                });
            }
            self.#create_page().then(function(){

            }, function(){

            });
        });

        return promise;
    }

    #create_define(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = T200Resource.merge_define(name);

            if(file){
                let define = new T200Define();

                if(define) {
                    define.create(file).then(function(obj){
                        self.object_values.push(obj);
                        resolve();
                    }, function(){

                    });
                }
            }
        });

        return promise;
    }

    #create_page() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let page = new T200Page();

            page.create(self).then(function(){
                
            }, function(){

            });
        });

        return promise;
    }
}

module.exports = T200LoginWeb;