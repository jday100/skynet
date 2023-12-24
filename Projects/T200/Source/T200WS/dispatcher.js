const fs = require('fs');
const url = require('url');
const path = require('path');

const wss = require('./wss.js');

class Dispatcher {
    constructor() {

    }

    run(req, res) {
        let data = url.parse(req.url, true);

        if('/server' == data.pathname){
            let server = new wss(req, res);

            server.open();
        }else{
            try{
                let result = this.load(data.pathname);
                res.end(result);
            }catch(err){
                res.end();
            };
        }
    }

    load(file) {
        if('/' == file){
            file = "/index.html";
        }
        let name = "./home" + file;
        let real = path.join(__dirname, name);
        return fs.readFileSync(real);
    }
}

module.exports = Dispatcher;