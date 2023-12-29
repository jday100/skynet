const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const formidable = require('formidable');
const urlparse = require('url');
const querystring = require('querystring');
const { unlink } = require('fs');

class T200HttpsRequest {
    constructor(req) {
        this.events = {};
        req.request = this;
        this.req = req;
        this.data = "";
        this.req.events = {};
        this.req.values = {};
    }

    load() {
        this.req.on('data', this.merge_data);
        this.req.on('end', this.parse_data);
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
                this.request.fields = {};
            }else{
                if(-1 != result.search.indexOf("?")){
                    let  str = result.search.slice(1);
    
                    this.request.fields = querystring.parse(str);
                }else{
                    this.request.fields = {};
                }
            }
            
        }else if("POST" == this.method){
            this.request.fields = querystring.parse(this.data);
        }

        let load = this.events['load'];
        if(load){
            log(__filename, "call load");
            load();
        }        
    }

    get(name) {
        log(__filename, "Request get", name);
        //return this.req.values[name];
        //return this.fields[name][0];

        let result = this.fields[name];

        if(undefined == result){
            return undefined;
        }else if(result instanceof Array){
            return result;
        }
        return result;
    }

    get_bool(name) {
        let value = this.req.fields[name];
        if(undefined == value || null == value){
            return false;
        }
        return true;
    }

    get_files() {
        return this.files;
    }
}

module.exports = T200HttpsRequest;