const child = require('child_process');

let server = child.exec(`cd ../web/ && node ./test_server.js`, function(){
    console.log("run");
});

server.on('exit', (code, signal) => {
    console.log('exit');
});

setTimeout(() => {
    //server.kill(process.SIGINT);

    //process.kill(server.pid, 'SIGINT');

    server.kill();

}, 5000);