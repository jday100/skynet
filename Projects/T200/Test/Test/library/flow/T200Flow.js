const T200Resource = require('../T200Resource.js');
const T200Define = require('../T200Define.js');
const T200Source = require('../T200Source.js');


class T200Flow {
    constructor(name) {
        this.name = name;
    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Define.create_web_flow(self.name).then(function(value){
                self.value = value;
            }, function(err){

            }).then(function(){
                return T200Source.create_flow_parser(self.name);
            }, function(err){

            }).then(function(parser){
                self.parser = parser;
                resolve();
            }, function(err){
                reject();
            });
        });
        return promise;
    }


    run(browser, tag) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            if(self.flow && self.flow.steps){
                for(let step of self.flow.steps){
                    await self.parser.parse(browser, element, step).then(function(){

                    }, function(err){
                        result = false;
                    });
                }
            }else{
                result = false;
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

module.exports = T200Flow;