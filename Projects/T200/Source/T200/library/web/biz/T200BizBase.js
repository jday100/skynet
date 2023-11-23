const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');


class T200BizBase {
    constructor() {

    }

    check() {
        if(undefined == this.store){
            
        }else{
            return true;
        }

        return false;
    }

    load(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                self.store.load(sql).then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }
    
}

module.exports = T200BizBase;