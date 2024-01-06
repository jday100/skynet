const T200Setup = require('../../project/T200Setup.js');
const T200StoreBase = require(T200Setup.external('./library/web/store/T200StoreBase.js'));


class T200Store extends T200StoreBase {
    constructor() {
        super();
    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self._client = global.database.client();
            resolve();
        });

        return promise;
    }
}

module.exports = T200Store;