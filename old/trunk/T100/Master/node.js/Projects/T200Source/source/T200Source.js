const { error, log } = require(`../library/T200Base.js`);
const T200SourceScanner = require(`./T200SourceScanner.js`);

class T200Source {
    constructor() {

    }

    static get_path() {
        let     result  = ".";

        result = process.argv[2];

        if("undefined" == result){
            result = ".";
        }
        return result;
    }

    static get_type() {
        let     result  = "cpp";

        result = process.argv[3];

        if("undefined" == result){
            result = "cpp";
        }
        return result;
    }

    static execute(path, type) {
        let scanner = new T200SourceScanner();

        scanner.execute(path, type);

        scanner.show_result();
    }
}

module.exports = T200Source;