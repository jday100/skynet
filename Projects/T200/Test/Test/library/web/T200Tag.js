class T200Tag {
    constructor() {

    }

    
    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Define.create_module(self.name).then(function(){

            }, function(err){

            }).then(function(){

            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_tag() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Define.create_module(self.name).then(function(){

            }, function(err){

            }).then(function(){

            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    #create_flow() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Define.create_module(self.name).then(function(){

            }, function(err){

            }).then(function(){

            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200Tag;