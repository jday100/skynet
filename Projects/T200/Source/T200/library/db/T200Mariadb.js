const T200Error = require('../T200Error.js');
const mariadb = require('mariadb');

const T200DBClient = require('./T200DBClient.js');


class T200Mariadb {
    constructor() {

    }

    start(setup) {
        let self = this;
        let flag = false;

        if(undefined == this.pool){
            flag = true;
            this.pool = mariadb.createPool(setup);
            this.setup = setup;
        }        
        
        let promise = new Promise(function(resolve, reject){
            if(flag){
                resolve()
            }else{
                reject(T200Error.build());
            }
        });

        return promise;
    }

    stop() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.pool){
                reject(T200Error.build());
            }else{
                self.pool.end().then(resolve, reject);
            }
        });

        return promise;
    }

    connect() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.pool){
                reject(T200Error.build());
            }else{
                return self.pool.getConnection().then(function(conn){
                    resolve(conn);
                }, function(err){
                    reject(T200Error.build());
                });
            }
        });

        return promise;
    }

    disconnect(conn) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.pool){
                reject(T200Error.build());
            }else{
                return conn.end().then(function(){
                    resolve();
                }, function(err){
                    reject(T200Error.build());
                });
            }
        });

        return promise;
    }

    client() {
        return new T200DBClient(this);
    }

}

module.exports = T200Mariadb;