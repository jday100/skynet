const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');

const T200DBSetup = require('../../library/db/T200DBSetup.js');
const T200DBClient = require('../../library/db/T200DBClient.js')
const T200Database = require('../../library/db/T200Database.js');

const T200HomeNoticeInit = require('./T200HomeNoticeInit.js');


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

        database.start(setup).then(function(){
            self.init().then(function(){

            }, function(){

            }).finally(function(){
                database.stop().then(function(){
                    
                }, function(){

                });
            });
        }, function(){

        });
    }

    init() {
        let HomeNoticeInit = new T200HomeNoticeInit();


        HomeNoticeInit.execute();
    }
}

log_start(__filename, "Home test data init");

let HomeTest = new T200HomeTest();

HomeTest.init();

log_stop(__filename, "Home test data init");