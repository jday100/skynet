class T200ScriptParser {
    constructor() {

    }

    run(method) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let flow = self.script[method];

            if(flow){

            }else{
                reject();
            }
        });
        
        return promise;
    }
}

module.exports = T200ScriptParser;