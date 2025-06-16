const T200Error = require(`../T200Error.js`);
const fs = require(`fs`);

class T200FileReader {
    #readStream;
    constructor() {

    }

    open(file) {
        this.#readStream = fs.createReadStream(file);
    }

    close() {
        fs.close(this.#readStream);
    }

    write(data) {
        this.#readStream.read(data);
    }
}

module.exports = T200FileReader;