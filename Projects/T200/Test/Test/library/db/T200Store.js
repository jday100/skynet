const T200Setup = require('../../project/T200Setup.js');
const T200StoreBase = require(T200Setup.external('./library/web/store/T200StoreBase.js'));


class T200Store {
    constructor() {

    }

    create() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self._client = global.database.client();
            resolve();
        });

        return promise;
    }

    connect() {
        return this._client.connect();
    }

    disconnect() {
        return this._client.disconnect();
    }

    query(sql) {
        return this._client.query(sql);
    }

    execute(sql) {
        return this._client.execute(sql);
    }
}

module.exports = T200Store;