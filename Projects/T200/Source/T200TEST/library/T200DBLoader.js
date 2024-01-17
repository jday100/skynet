const T200Setup = require('../project/T200Setup');
const T200DBSetup = require('../project/T200DBSetup');

const T200Database = require(T200Setup.external('./library/db/T200Database.js'));


class T200DBLoader {
    constructor() {

    }

    start() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == T200Setup.db_setup 
                || '' == T200Setup.db_setup){
                    resolve();
            }else{
                setTimeout(async function(){
                    let database = new T200Database();

                    database.setup = new T200DBSetup();
    
                    await database.start().then(function(){
                        global.database = database;
                        resolve();
                    }, function(err){
                        reject();
                    });
                });                
            }
        });

        return promise;
    }

    stop() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == global.database){
                resolve();
            }else{
                await global.database.stop().then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }
}

module.exports = T200DBLoader;