const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Crypto = require('../../library/crypto/T200Crypto.js');


function test_crypto() {
    let result;

    let item = "0beec7b5ea3f0fdbc95d0dd47f3c5bc275da8a33";
    let value = T200Crypto.sha1("foo");;

    if(item == value){
        result = true;
    }else{
        result = false;
    }

    return result;
}

log_start(__filename, "test crypto");

let result;

result = test_crypto();

if(result){
    log(__filename, "test crypto success!");
}else{
    log(__filename, "test crypto failure!");
}

log_stop(__filename, "test crypto");