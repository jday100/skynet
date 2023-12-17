const T200Error = require('../T200Error.js');
const mysql = require('mysql');

const T200DBClient = require('./T200DBClient.js');


class T200Mysql {
    constructor() {

    }
    
    start(setup) {
        let self = this;
        let flag = false;

        if(undefined == this._pool){
            flag = true;
            this._pool = mysql.createPool(setup);
            this._setup = setup;
        }        
        
        let promise = new Promise(function(resolve, reject){
            if(flag){
                resolve()
            }else{
                reject();
            }
        });

        return promise;
    }

    stop() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._pool){
                reject();
            }else{
                self._pool.end().then(resolve, reject);
            }
        });

        return promise;
    }

    connect() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._pool){
                reject(T200Error.build());
            }else{
                self._pool.getConnection().then(function(conn){
                    resolve(conn);
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }

    disconnect(conn) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._pool){
                reject();
            }else{
                conn.end().then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }

    client() {
        return new T200DBClient(this);
    }
}

module.exports = T200Mysql;