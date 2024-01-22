const T200Source = require('./T200Source.js');


class T200Actuator {
    constructor() {

    }

    run(category, project, type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == source || source.endsWith("/")) {
                await self.#search(category, project, type, source).then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }else{
                await self.#done(category, project, type, source, method, subdir).then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }

    #search(category, project, type, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){

        });

        return promise;
    }

    #done(category, project, type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(source.endsWith(".script")){
                await T200Source.create_script(category, project, source).then(async function(script){
                    script.category = category;
                    script.project = project;
                    script.type = type;
                    await script.run(method).then(function(){
                        resolve();
                    }, function(err){
                        reject();
                    });
                }, function(err){
                    reject();
                });
            }else if(source.endsWith(".js")){

            }else{

            }
        });

        return promise;
    }
}

module.exports = T200Actuator;