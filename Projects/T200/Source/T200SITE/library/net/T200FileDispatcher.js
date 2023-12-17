const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const url = require('url');
const T200File = require('../fs/T200File.js');
const T200Path = require('../fs/T200Path.js');


class T200FileDispatcher {
    constructor() {

    }

    run(req, res) {
        let data =url.parse(req.url, true);

        this.load(data.pathname).then(function(result){
            res.end(result);
        }, function(){
            res.writeHead(404);
            res.end();
        });
    }

    load(file) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let name;

            if(file.endsWith('/')){
                name = file + "index.html";
            }else{
                name = file;
            }
    
            let real = T200Path.join_root("home" + name);
    
            return T200File.load(real).then(resolve, reject);
        });

        return promise;
    }
}

module.exports = T200FileDispatcher;