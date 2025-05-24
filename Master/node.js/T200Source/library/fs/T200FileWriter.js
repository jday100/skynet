const T200Error = require(`../T200Error.js`);
const fs = require(`fs`);

class T200FileWriter {
    #writeStream;
    constructor() {

    }

    open(file) {
        this.#writeStream = fs.createWriteStream(file);
    }

    close() {
        fs.close(this.#writeStream);
    }

    write(data) {
        this.#writeStream.write(data);
    }
}

module.exports = T200FileWriter;