const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');

const T200Moken = require('../../library/T200Moken.js');


console.log(T200Moken.mock_int(0, 100));

for(let i=0;i<100;i++){
    console.log(T200Moken.mock_int(0, 100));
}

for(let i=0;i<100;i++){
    console.log(T200Moken.mock_letter());
}

for(let i=0;i<100;i++){
    console.log(T200Moken.mock_string(6, 50));
}

for(let i=0;i<100;i++){
    console.log(T200Moken.mock_chinese(6, 50));
}