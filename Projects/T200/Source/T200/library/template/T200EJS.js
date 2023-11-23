const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');
const ejs = require('ejs');


class T200EJS {
    constructor() {

    }

    render_file(file, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            log(__filename, "render_file", file);
            ejs.renderFile(file, data, function(err, result){
                if(err){
                    reject(T200Error.bind());
                }else{
                    resolve(result);
                }
            });
        });

        return promise;
    }
}

module.exports = T200EJS;