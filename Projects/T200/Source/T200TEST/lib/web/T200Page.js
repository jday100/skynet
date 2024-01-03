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

            element.type = "link";
            element.value = "http://localhost:8888/";

            self.#create_element(element).then(function(){
                resolve();
            }, function(err){

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
    
                    });
                    break;
            }
        });

        return promise;        
    }

    test(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            for(let element of self.elements){
                element.test(browser).then(function(){

                }, function(){

                });
            }

            resolve();
        });

        return promise;
    }
}

module.exports = T200Page;