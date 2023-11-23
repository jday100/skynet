const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const urlparse = require('url');
const querystring = require('querystring');

class T200HttpsRequest {
    constructor(req) {
        this.events = {};
        this.req = req;
        this.data = "";
        this.req.events = {};
        req.on('data', this.merge_data);
        req.on('end', this.parse_data);
    }

    on(name, callback) {
        log(__filename, "on", name);
        this.req.events[name] = callback;
    }

    merge_data(current) {
        log(__filename, "merge_data", current);
        this.data += current;
    }

    parse_data() {
        log(__filename, "parse_data", this.data);

        if("GET" == this.method){
            let result = urlparse.parse(this.url, true);
            if(null == result.search){

            }else{
                if(-1 != result.search.indexOf("?")){
                    let  str = result.search.slice(1);
    
                    this.values = querystring.parse(str);
                }
            }
            
        }else if("POST" == this.method){
            this.values = querystring.parse(this.data);
        }

        let load = this.events['load'];
        if(load){
            log(__filename, "call load");
            load();
        }        
    }

    get(name) {
        log(__filename, "Request get", name);
        return this.req.values[name];
    }
}

module.exports = T200HttpsRequest;