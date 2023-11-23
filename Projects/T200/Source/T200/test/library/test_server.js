const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');

const T200HttpsServer = require('../../library/net/T200HttpsServer.js');


log_start(__filename, "test_https_server");

let server = new T200HttpsServer();

server.start();


log_stop(__filename, "test_https_server");


