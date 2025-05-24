const { log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const T200DBSetup = require('./T200DBSetup.js');


class T200Database {
    constructor() {
        this.setup = new T200DBSetup();
    }

    start() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.database){

            }else{
                reject(T200Error.build());
                return;
            }

            switch(self.setup.type){
                case 'mysql':
                    log(__filename, "mysql");

                    const T200Mysql = require('./T200Mysql.js');
                    self.database = new T200Mysql();
                    self.database.start(self.setup).then(resolve, reject);
                    break;
                case 'mariadb':
                    log(__filename, "mariadb");

                    const T200Mariadb = require('./T200Mariadb.js');
                    self.database = new T200Mariadb();
                    self.database.start(self.setup).then(resolve, reject);
                    break;
            }
        });

        return promise;
    }

    stop() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self.database){
                reject(T200Error.build());
            }else{
                self.database.stop().then(resolve, reject);
            }
        });

        return promise;
    }

    client() {
        let self = this;

        if(undefined == self.database){
            
        }else{
            return self.database.client();
        }

        return undefined;
    }
}

module.exports = T200Database;