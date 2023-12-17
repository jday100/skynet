const T200Error = require('../T200Error.js');


class T200DBClient {
    constructor(db) {
        this._database = db;
    }

    connect() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._database){
                reject();
            }else{
                return self._database.connect().then(function(conn){
                    self._conn = conn;
                    resolve();
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }

    disconnect() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._database){
                reject();
            }else{
                return self._database.disconnect(self._conn).then(function(){
                    delete self._conn;
                    resolve();
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }

    query(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._database){
                reject();
            }else{
                self._conn.query(sql).then(function(data){
                    resolve(data);
                }, function(err){
                    reject();
                }).catch(function(err){
                    reject();
                });
            }
        });

        return promise;
    }

    execute(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._database){
                reject();
            }else{
                return self._conn.query(sql).then(function(data){
                    resolve(data);
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }

    begin() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._database){
                reject();
            }else{
                self._conn.beginTransaction().then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }

    commit() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._database){
                reject();
            }else{
                self._conn.commit().then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }

    rollback() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._database){
                reject();
            }else{
                self._conn.rollback().then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }
}

module.exports = T200DBClient;