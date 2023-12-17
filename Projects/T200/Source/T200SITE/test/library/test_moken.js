const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Moken = require('../../library/T200Moken.js');

function test_moken() {
    let result;

    for(let i=0;i<10;i++){
        let value = T200Moken.mock_int(1, 10);

        console.log(value);
        if(value >= 1 && value <= 10){
            result = true;
        }else{
            result = false;
            break;
        }
    }
    console.log("");
    for(let i=0;i<10;i++){
        let value = T200Moken.mock_int(-10, 10);

        console.log(value);
        if(value >= -10 && value <= 10){
            result = true;
        }else{
            result = false;
            break;
        }
    }

    return result;
}

function test_chinese() {
    let result;

    for(let i=0;i<100;i++){
        let value = T200Moken.mock_chinese(1, 10);

        console.log(value);
        if(value.length >= 1 && value.length <= 10){
            result = true;
        }else{
            result = false;
            break;
        }
    }
    console.log("");

    return result;
}

log_start(__filename, "test moken");

let result;

result = test_moken();

result = result ? test_chinese() : false;

if(result){
    log(__filename, "test moken success!");
}else{
    log(__filename, "test moken failure!");
}

log_stop(__filename, "test moken");