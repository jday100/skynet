const { log, log_start, log_stop } = require('./library/T200Lib.js');
const T200HomeServer = require('./project/T200HomeServer.js');

log_start(__filename, "Home Server");

let HomeServer = new T200HomeServer();

HomeServer.start().then(function(){
    log(__filename, "HomeServer start success");
}, function(){
    log(__filename, "HomeServer start failure");
});

log_stop(__filename, "Home Server");