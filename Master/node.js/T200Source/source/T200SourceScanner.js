const { error, log } = require(`../library/T200Base.js`);
const T200Path = require(`../library/fs/T200Path.js`);
const T200FileWriter = require(`../library/fs/T200FileWriter.js`);
const T200SourceParser = require(`./T200SourceParser.js`);
const T200SourceParserFactory = require(`./T200SourceParserFactory.js`);

class T200SourceScanner {
    constructor() {

    }

    static line;

    static #result;
    static #type;

    execute(path, type) {
        let self = this;
        T200SourceScanner.#type = type;
        T200Path.exists(path).then(function(){
            console.log("exists");
            T200SourceScanner.#result = new T200FileWriter();

            let     file = path + "/result.txt";
            T200SourceScanner.#result.open(file);

            self.list(path);

            //T200SourceScanner.#result.close();
        },function(){
            console.log("not exists");
        });
    }

    list(path) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            T200Path.list(path).then(function(result){
                console.log(result);
                let data = "";
                
                result.files.forEach(element => {
                    console.log(element);
                    
                    data += element + "\n";
                    
                    let parser  = T200SourceParserFactory.create(T200SourceScanner.#type);

                    let line    = parser.parse(element);

                    T200SourceScanner.line += line;
                });

                result.dirs.forEach(element => {
                    self.list(path + "/" + element);
                });

                T200SourceScanner.#result.write(data);
            }, function(result){
                console.log(result);
            });
        });

        return promise;
    }

    show_result() {
        console.log(T200SourceScanner.line);
    }
}

module.exports = T200SourceScanner;