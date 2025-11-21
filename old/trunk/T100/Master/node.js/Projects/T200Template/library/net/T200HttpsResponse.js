const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');


class T200HttpsResponse {
    constructor(res) {
        this.res = res;

        this.paras = {};
        this._status = 200;
        this._type = "text";
        this._result = false;
        this._data = "";
    }

    status(value) {
        log(__filename, "set status", value);
        this._status = value;
    }

    type(value) {
        log(__filename, "set type", value);
        this._type = value;
    }

    data(value) {
        log(__filename, "set data");
        this._data = value;
    }

    set(name, value) {
        log(__filename, "set", name);
        this.res.setHeader(name, value);
    }

    success(data) {
        this._status = 200;
        this._data = data;
        this._result = true;
    }

    failure() {
        this._result = false;
    }

    error() {
        this._status = 500;
    }

    SEND_END() {
        log(__filename, "SEND_END");

        switch(this._status){
            case 200:
                if(this._result){
                    switch(this._type){
                        case "text":
                            //console.log(this._data);
                            this.res.end(this._data);
                            break;
                        case "json":
                            if(this._result){
                                this.paras['result'] = "success";
                                this.paras['data'] = this._data;
                            }else{
                                this.paras['result'] = "failure";
                            }
                            
                            this.res.end(JSON.stringify(this.paras));
                            break;
                    }
                }else{
                    switch(this._type){
                        case "text":
                            this.res.end(this._data);
                            break;
                        case "json":
                            this.paras['result'] = "failure";

                            this.res.end(JSON.stringify(this.paras));
                            break;
                    }
                }
                
                break;
            case 404:
                this.res.writeHead(this._status);
                switch(this._type){
                    case "text":
                        this.res.end(this._data);
                        break;
                    case "json":
                        this.res.end(JSON.stringify(this.paras));
                        break;
                }
                break;
            case 500:
                this.res.writeHead(this._status);
                switch(this._type){
                    case "text":
                        this.res.end(this._data);
                        break;
                    case "json":
                        this.res.end(JSON.stringify(this.paras));
                        break;
                }
                break;
        }
    }

}

module.exports = T200HttpsResponse;