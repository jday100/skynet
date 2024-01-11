const child = require('child_process');

process.on("SIGINT", function(){
    console.log("sigint");
    process.exit(0);
});

process.on("SIGTERM", function(){
    console.log("sigterm");
    process.exit(0);
});

process.on("exit", function(){
    console.log('exit');
});


for(let i=0;i<100;i++){
    Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, 1000);
    process.exit(0);
    console.log(i);
}