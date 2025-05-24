const { error, log } = require('../library/T200Lib.js');
const T200Error = require('../library/T200Error.js');
const T200ReadLine = require(`readline`);
const fs = require(`fs`);

const T200EJS = require(`../library/template/T200EJS.js`);
const T200File = require(`../library/fs/T200File.js`);

class T200Template {
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

        T200Template.#build(source, target);
    }

    static #build(source, target) {
        let readline = T200ReadLine.createInterface({
            input:fs.createReadStream(source)
        });

        let data    = new Array();
        let result  = {};

        readline.on('line', (line) => {
            console.log(`${line}`);
            data.push(line);
        });

        readline.on('close', ()=>{
            let ejs = new T200EJS();

            result.files = data;
            ejs.render_file("./template/index.ejs", result).then(function(value){
                console.log(value);
                T200File.save("./home/index.html", value);
            }, function(err){
                console.log(err);
            });
        });
    }
}

module.exports = T200Template;