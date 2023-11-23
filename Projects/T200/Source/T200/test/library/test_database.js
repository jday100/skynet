const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const T200DBSetup = require('../../library/db/T200DBSetup.js');
const T200Database = require('../../library/db/T200Database.js');


log_start(__filename, "test_database");

let setup = new T200DBSetup();
let database = new T200Database();

database.setup.database = "home";
database.setup.user = "home";
database.setup.password = "home123";

let result = false;

database.start(setup).then(function(){
    log(__filename, "database start success");

    return database.connect().then(function(){
        log(__filename, "database connect success");
        let sql = "select * from per1son";

        return database.query(sql).then(function(data){
            log(__filename, "database query success");
            result = true;
        }, function(err){
            log(__filename, "database query failure");
            result = false;
        }).catch(function(){
            log(__filename, "database query catch");
            result = false;
        }).finally(function(){

            return database.disconnect();

        }).then(function(){
            log(__filename, "database disconnect success");
        }, function(){
            log(__filename, "database disconnect failure");
            result = false;
        }).catch(function(){
            log(__filename, "database disconnect catch");
            result = false;
        });

    }, function(){
        log(__filename, "database connect failure");
    }).catch(function(){
        log(__filename, "database connect catch");
    }).finally(function(){

        return database.stop()

    }).then(function(){
        log(__filename, "database stop success");
    }, function(){
        log(__filename, "database stop failure");
        result = false;
    }).catch(function(){
        log(__filename, "database stop catch");
        result = false;
    });

}, function(){
    log(__filename, "database start failure");
}).catch(function(){
    log(__filename, "database start error");
}).finally(function(){
    if(result){
        log(__filename, "test database success");
    }else{
        log(__filename, "test database failure");
    }
});


log_stop(__filename, "test_database");