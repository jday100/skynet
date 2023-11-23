const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');


class T200HomeClear {
    constructor() {
        this.tables = [
            'person'
            ];
    }

    async clear(client) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = false;
            self.dotter.hit(6);
            for(let item of self.tables){
                await client.execute(self.merge_clear(item)).then(function(){
                    result = true;
                }, function(err){
                    result = false;
                });

                if(!result)break;
            }
            self.dotter.hit(8);
            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }

    merge_clear(name) {
        this.dotter.hit(7);
        return `drop table if exists ${name}`;
    }
}

module.exports = T200HomeClear;