const T200Error = require('../T200Error.js');

class T200DBClient {
    constructor(db) {
        this.database = db;
    }

    connect() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.database){
                reject(T200Error.build());
            }else{
                return self.database.connect().then(function(conn){
                    self._conn = conn;
                    resolve();
                }, function(err){
                    reject(T200Error.build());
                });
            }
        });

        return promise;
    }

    disconnect() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.database){
                reject(T200Error.build());
            }else{
                return self.database.disconnect(self._conn).then(function(){
                    delete self._conn;
                    resolve();
                }, function(err){
                    reject(err);
                });
            }
        });

        return promise;
    }

    query(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.database){
                reject(T200Error.build());
            }else{
                self._conn.query(sql).then(function(data){
                    resolve(data);
                }, function(err){
                    reject(T200Error.build());
                });
            }
        });

        return promise;
    }

    async execute(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.database){
                reject(T200Error.build());
            }else{
                return self._conn.query(sql).then(function(data){

                    resolve(data);
                }, function(err){
                    reject(T200Error.build());
                });
            }
        });

        return promise;
    }

    begin() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.database){
                reject(T200Error.build());
            }else{
                self._conn.beginTransaction().then(function(){
                    resolve();
                }, function(err){
                    reject(T200Error.build());
                });
            }
        });

        return promise;
    }

    commit() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.database){
                reject(T200Error.build());
            }else{
                self._conn.commit().then(function(){
                    resolve();
                }, function(err){
                    reject(T200Error.build());
                });
            }
        });

        return promise;
    }

    rollback() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.database){
                reject(T200Error.build());
            }else{
                self._conn.rollback().then(function(){
                    resolve();
                }, function(err){
                    reject(T200Error.build());
                });
            }
        });

        return promise;
    }
}

module.exports = T200DBClient;