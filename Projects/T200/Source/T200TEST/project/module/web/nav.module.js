class T200NavModule {
    constructor() {
        this.name = "nav";
        this.values = new Array();
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.#create_module(self.name).then(resolve, reject);
        });

        return promise;
    }

    #create_module(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let file = T200Resource.merge_web_define(name);

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
}

module.exports = T200NavModule;