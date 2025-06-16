const { error, log } = require(`../library/T200Base.js`);
const T200SourceCppParser   = require(`./T200SourceCppParser.js`);

class T200SourceParserFactory {
    constructor() {

    }

    static create(type) {
        return new T200SourceCppParser();
    }
}

module.exports = T200SourceParserFactory;