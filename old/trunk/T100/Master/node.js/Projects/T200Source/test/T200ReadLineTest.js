const {log, log_start, log_stop} = require(`../library/T200Base.js`);
const T200ReadLine = require(`readline`);
const fs = require(`fs`);

log_start(__filename, "T200ReadLineTest");

let file = "./test/T200ReadLineTest.js";
let readline = T200ReadLine.createInterface({
    input:fs.createReadStream(file)
}); 

readline.on('line', (line) => {
    console.log(`${line}`);
});

log_stop(__filename, "T200ReadLineTest");