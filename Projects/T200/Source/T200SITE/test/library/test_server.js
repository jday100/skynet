const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');

const T200HttpsServer = require('../../library/net/T200HttpsServer.js');


log_start(__filename, "test_https_server");

let server = new T200HttpsServer();

server.start().then(function(){
    log(__filename, "server start success!");
}, function(){
    log(__filename, "server start failure!");
});


log_stop(__filename, "test_https_server");