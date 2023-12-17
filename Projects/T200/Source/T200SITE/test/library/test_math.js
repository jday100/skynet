const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Math = require('../../library/T200Math.js');

function test_random() {
    let result;

    for(let i=0;i<10;i++){
        let value = T200Math.random(1, 10);

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
        let value = T200Math.random(10, 1);

        console.log(value);
        if(value >= 1 && value <= 10){
            result = true;
        }else{
            result = false;
            break;
        }
    }

    return result;
}

log_start(__filename, "test math");

let result;

result = test_random();

if(result){
    log(__filename, "test math success!");
}else{
    log(__filename, "test math failure!");
}

log_stop(__filename, "test math");