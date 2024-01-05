const T200Link  = require('./elements/T200Link.js');


class T200Page {
    constructor() {
        this.elements = new Array();
    }

    create(web) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            //test

            let element = {};

            element.url = "http://localhost:8888/login.html";
            element.type = "link";
            element.value = "http://localhost:8888/";
            element.locate_type = "css";
            element.locate_value = 'a[locale="home"]';

            self.#create_element(element).then(function(){
                resolve();
            }, function(){
                reject();
            });
        });

        return promise;
    }

    #create_element(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            switch(element.type){
                case 'link':
                    let obj = new T200Link();
    
                    obj.create(element).then(function(){
                        self.elements.push(obj);
                        resolve();
                    }, function(){
                        reject();
                    });
                    break;
            }
        });

        return promise;        
    }

    run(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            for(let element of self.elements){
                await element.run(browser).then(function(){

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
}

module.exports = T200Page;