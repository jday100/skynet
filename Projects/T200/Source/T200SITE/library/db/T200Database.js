const { log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const T200DBSetup = require('./T200DBSetup.js');


class T200Database {
    constructor() {
        this._setup = new T200DBSetup();
    }

    start() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._database){

            }else{
                reject();
                return;
            }

            switch(self._setup.type){
                case 'mysql':
                    log(__filename, "mysql");

                    const T200Mysql = require('./T200Mysql.js');
                    self._database = new T200Mysql();
                    self._database.start(self._setup).then(resolve, reject);
                    break;
                case 'mariadb':
                    log(__filename, "mariadb");

                    const T200Mariadb = require('./T200Mariadb.js');
                    self._database = new T200Mariadb();
                    self._database.start(self._setup).then(resolve, reject);
                    break;
            }
        });

        return promise;
    }

    stop() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(undefined == self._database){
                reject();
            }else{
                self._database.stop().then(resolve, reject);
            }
        });

        return promise;
    }

    client() {
        let self = this;

        if(undefined == self._database){
            
        }else{
            return self._database.client();
        }

        return undefined;
    }
}

module.exports = T200Database;