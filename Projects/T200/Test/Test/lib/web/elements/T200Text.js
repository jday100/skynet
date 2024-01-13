const T200Data = require('../../T200Data.js');


class T200Text {
    constructor() {

    }

    create(element) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.url = element.url;
            self.name = element.name;
            self.type = element.type;
            self.target = element.target;
            self.value = element.value;
            self.locate = element.locate;

            let data = {};

            data.type = element.type;
            self.data = data;

            await self.#create_data().then(function(){
                resolve();
            }, function(){
                reject();
            });            
        });

        return promise;
    }

    #create_data() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(T200Data.build(self.data)){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }

    run(browser, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            browser.locate(self.locate).then(function(element){
                if(element){
                    element.input(data).then(resolve, reject);
                }else{
                    reject();
                }
            },function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200Text;