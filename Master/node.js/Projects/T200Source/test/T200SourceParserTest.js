const {log, log_start, log_stop} = require(`../library/T200Base.js`);
const T200ReadLine = require(`readline`);
const fs = require(`fs`);

log_start(__filename, "T200SourceParserTest");

let file = "./test/T200ReadLineTest.js";
let readline = T200ReadLine.createInterface({
    input:fs.createReadStream(file)
}); 

readline.on('line', (line) => {
    console.log(`${line}`);

    let length = line.length;

    for(let i=0;i<length;i++){
        let letter = line.charAt(i);
        console.log(`${letter}`);
    }

});

log_stop(__filename, "T200SourceParserTest");