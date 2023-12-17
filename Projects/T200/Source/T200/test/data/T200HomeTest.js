const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');

const T200DBSetup = require('../../library/db/T200DBSetup.js');
const T200DBClient = require('../../library/db/T200DBClient.js')
const T200Database = require('../../library/db/T200Database.js');

const T200HomeHouseRentInit = require('./T200HomeHouseRentInit.js');
const T200HomeHouseWantedInit = require('./T200HomeHouseWantedInit.js');
const T200HomeJobRecruitInit = require('./T200HomeJobRecruitInit.js');
const T200HomeJobWantedInit = require('./T200HomeJobWantedInit.js');
const T200HomeTradingSellInit = require('./T200HomeTradingSellInit.js');
const T200HomeTradingBuyInit = require('./T200HomeTradingBuyInit.js');
const T200HomeExchangeInit = require('./T200HomeExchangeInit.js');

const T200HomeAdminInit = require('./T200HomeAdminInit.js');
const T200HomeSettingInit = require('./T200HomeSettingInit.js');
const T200HomePersonInit = require('./T200HomePersonInit.js');
const T200HomeIdentityInit = require('./T200HomeIdentityInit.js');
const T200HomeInvitationInit = require('./T200HomeInvitationInit.js');
const T200HomeAdvertInit = require('./T200HomeAdvertInit.js');
const T200HomeNoticeInit = require('./T200HomeNoticeInit.js');
const T200HomeNoteInit = require('./T200HomeNoteInit.js');


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
            console.log("Success!");
        }, function(){
            console.log("Failure!");
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
            let HomePersonInit = new T200HomePersonInit();
            
            return HomePersonInit.execute(client).then(function(){
                let HomeIdentityInit = new T200HomeIdentityInit();
                return HomeIdentityInit.execute(client);
            }, function(){

            }).then(function(){
                let HomeInvitationInit = new T200HomeInvitationInit();
                return HomeInvitationInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeAdminInit = new T200HomeAdminInit();
                return HomeAdminInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeSettingInit = new T200HomeSettingInit();
                return HomeSettingInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeAdvertInit = new T200HomeAdvertInit();
                return HomeAdvertInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeNoticeInit = new T200HomeNoticeInit();
                return HomeNoticeInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeNoteInit = new T200HomeNoteInit();
                return HomeNoteInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeHouseRentInit = new T200HomeHouseRentInit();
                return HomeHouseRentInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeHouseWantedInit = new T200HomeHouseWantedInit();
                return HomeHouseWantedInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeJobRecruitInit = new T200HomeJobRecruitInit();
                return HomeJobRecruitInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeJobWantedInit = new T200HomeJobWantedInit();
                return HomeJobWantedInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeTradingSellInit = new T200HomeTradingSellInit();
                return HomeTradingSellInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeTradingBuyInit = new T200HomeTradingBuyInit();
                return HomeTradingBuyInit.execute(client);
            }, function(){
                return error();
            }).then(function(){
                let HomeExchangeInit = new T200HomeExchangeInit();
                return HomeExchangeInit.execute(client);
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
}

log_start(__filename, "Home test data init");

let HomeTest = new T200HomeTest();

HomeTest.start();

log_stop(__filename, "Home test data init");