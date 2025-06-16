const { error, log } = require(`../library/T200Base.js`);
const T200SourceParser = require(`./T200SourceParser.js`);
const T200SourceReader = require(`./T200SourceReader.js`);

class T200SourceCppParser extends T200SourceParser {
    constructor() {
        super();
    }

    parse(file, type) {
        let reader = new T200SourceReader();

        reader.open(file);

        reader.close();

        return 1;
    }

    #parseLetter(letter) {
        
    }
}

module.exports = T200SourceCppParser;