const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');

const T200DBSetup = require('../../library/db/T200DBSetup.js');
const T200Mariadb = require('../../library/db/T200Mariadb.js');

const T200Dotter = require('../../library/T200Dotter.js');

log_start(__filename, "test_mariadb");

let setup = new T200DBSetup();
let mariadb = new T200Mariadb();
let dotter = new T200Dotter();

setup.database = "home";
setup.user = "home";
setup.password = "home123";

let result = false;
let client;

dotter.hit(1);
mariadb.start(setup).then(function(){
    dotter.hit(2);
    client = mariadb.client();

    return client.connect().then(function(){
        dotter.hit(3);
        let sql = "select * from person";

        return client.query(sql).then(function(data){
            dotter.success(4);
        }, function(){
            dotter.failure(5);
        }).finally(function(){
            return client.disconnect().then(function(){
                dotter.hit(6);
            }, function(){
                dotter.failure(7);
            });
        });
    }, function(){
        dotter.failure(8);
    }).finally(function(){
        dotter.hit(9);
        return mariadb.stop().then(function(){
            dotter.hit(10);
        }, function(){
            dotter.failure(11);
        });
    });
        
}, function(err){
    dotter.failure(12);
    return error();
}).finally(function(){
    dotter.hit(13);
    if(dotter.judge()){
        log(__filename, "dot success");
    }else{
        log(__filename, "dot failure")
    }
});




log_stop(__filename, "test_mariadb");