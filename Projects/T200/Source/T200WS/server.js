const http = require('http');

const wss = require('./wss.js');
const Dispatcher = require('./dispatcher.js');

let server = http.createServer();

server.on('request', function(req, res){

    let dispatcher = new Dispatcher();

    dispatcher.run(req, res);
});

server.on('upgrade', function(req, res){
    console.log(1);

    let ws = new wss(req, res);

    ws.upgrade();
});


server.on('listen', function(){

});

server.listen(8888);