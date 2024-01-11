const { log, log_start, log_stop } = require('./library/T200Lib.js');
const T200HomeServer = require('./project/T200HomeServer.js');

log_start(__filename, "Home Server");

let HomeServer = new T200HomeServer();

process.on("SIGINT", function(){
    console.log("sigint");
});

process.on("SIGTERM", function(){
    console.log("sigterm");
});

process.on("SIGKILL", function(){
    console.log("sigkill");
});

setTimeout(() => {
    //HomeServer.stop();
    /*.then(function(){
        console.log("stop success");
    }, function(){
        console.log("stop failure");
    });*/
}, 5000);

HomeServer.start().then(function(){
    log(__filename, "HomeServer start success");
}, function(){
    log(__filename, "HomeServer start failure");
});

log_stop(__filename, "Home Server");