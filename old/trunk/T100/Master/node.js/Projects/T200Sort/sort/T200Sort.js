const { error, log } = require(`../library/T200Base.js`);
const T200File = require(`../library/fs/T200File.js`);
const T200ReadLine = require(`readline`);
const fs = require(`fs`);

class T200Sort {
    constructor() {

    }

    static execute() {
        let     source;
        let     target;

        source  = process.argv[2];
        if("undefined" == source){
            return;
        }

        target  = process.argv[3];
        if("undefined" == target){
            return;
        }

        T200Sort.#sort(source, target);
    }

    static #sort(source, target) {
        let readline = T200ReadLine.createInterface({
            input:fs.createReadStream(source)
        });

        let data    = new Array();
        let result  = "";

        readline.on('line', (line) => {
            console.log(`${line}`);
            data.push(line);
        });

        readline.on('close', ()=>{
            data.sort();
            data.forEach(element =>{
                result += element + "\n";
            });
            T200File.save(target, result);
        });
    }
}

module.exports = T200Sort;
