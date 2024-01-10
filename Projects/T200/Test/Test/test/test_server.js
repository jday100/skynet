const child = require('child_process');

let server = child.exec(`cd ../web/ && node ./T200Home.js`);

setTimeout(() => {
    //let result = server.kill('SIGTERM');
    let result = server.kill();
    console.log(result);
}, 5000);