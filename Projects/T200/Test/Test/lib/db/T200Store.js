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
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self._client.connect().then(resolve, reject);
        });

        return promise;
    }

    disconnect() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self._client.disconnect().then(resolve, reject);
        });

        return promise;
    }

    query(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self._client.query(sql).then(resolve, reject);
        });

        return promise;
    }

    execute(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self._client.execute(sql).then(resolve, reject);
        });

        return promise;
    }
}

module.exports = T200Store;