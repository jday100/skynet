const T200Error = require('../T200Error.js');
const mysql = require('mysql');

const T200DBClient = require('./T200DBClient.js');
const T200MysqlClient = require('./T200MysqlClient.js');


class T200Mysql {
    constructor() {

    }
    
    start(setup) {
        let self = this;
        let flag = false;

        if(undefined == this.pool){
            flag = true;
            this.pool = mysql.createPool(setup);
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
                self.pool.end(function(err){
                    resolve();
                });
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
                self.pool.getConnection(function(err, conn){
                    if(err){
                        reject(T200Error.build());
                    }else{
                        resolve(conn);
                    }
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
                conn.release();
                resolve();
            }
        });

        return promise;
    }

    client() {
        return new T200DBClient(new T200MysqlClient(this));
    }
}

module.exports = T200Mysql;