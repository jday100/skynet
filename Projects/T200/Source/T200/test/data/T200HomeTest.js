const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');

const T200DBSetup = require('../../library/db/T200DBSetup.js');
const T200DBClient = require('../../library/db/T200DBClient.js')
const T200Database = require('../../library/db/T200Database.js');

const T200HomeNoticeInit = require('./T200HomeNoticeInit.js');
const T200HomePersonInit = require('./T200HomePersonInit.js');

class T200HomeTest {
    constructor() {

    }

    start() {
        let self = this;
        let setup = new T200DBSetup();
        let database = new T200Database();
        
        setup.database = "home";
        setup.user = "home";
        setup.password = "home123";

        let result;
        database.setup = setup;
        database.start().then(function(){
            return self.init(database.client()).then(function(){
                result = true;
            }, function(){
                result = false;
            }).finally(function(){
                return database.stop().then(function(){
                    
                }, function(){
                    result = false;
                });
            });
        }, function(){
            result = false;
        }).then(function(){

        }, function(){

        });
    }

    init(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return client.connect().then(function(){
                return self.execute(client).finally(function(){
                    return client.disconnect();
                });
            }, function(){
                return error();
            }).then(function(){
                resolve();
            }, function(){
                reject();
            });
        });

        return promise;
    }

    execute(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let HomeNoticeInit = new T200HomeNoticeInit();
            
            return HomeNoticeInit.execute(client).then(function(){
                let HomePersonInit = new T200HomePersonInit();
                return HomePersonInit.execute(client);
            }, function(){

            }).then(function(){
                resolve();
            }, function(){
                reject();
            });
        });

        return promise;
    }
}

log_start(__filename, "Home test data init");

let HomeTest = new T200HomeTest();

HomeTest.start();

log_stop(__filename, "Home test data init");