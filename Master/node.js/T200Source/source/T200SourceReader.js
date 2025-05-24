const { error, log } = require(`../library/T200Base.js`);
const T200ReadLine = require(`readline`);
const fs = require(`fs`);

class T200SourceReader {
    constructor() {

    }

    #readline;

    open(file) {
        return;
        this.#readline = T200ReadLine.createInterface({
            input:fs.createReadStream(file)
        }); 

    }

    close() {

    }

    read() {
        
    }
}

module.exports = T200SourceReader;