function error(msg) {
    return new Promise(function(resolve, reject){
        reject(msg);
    });
}

function log(file, msg, data) {
    console.log(`[ ${file} ]\n\t: { ${msg} } \n\t=> ( ${data} )`);
}

/*
function log(file, msg, data) {

}
*/

function log_start(file, msg) {
    console.log(`[ ${file} ]\n\t: { ${msg} } [start]`);
}

function log_stop(file, msg) {
    console.log(`[ ${file} ]\n\t: { ${msg} } [stop]`);
}

function sleep(value) {
    Atomics.wait(new Int32Array(new SharedArrayBuffer(4)), 0, 0, value);
}


module.exports = { error, log, log_start, log_stop };