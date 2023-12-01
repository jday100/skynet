const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');



class T200HttpsSession {
    constructor(cookie) {
        this.cookie = cookie;
    }

    static clear() {
        log(__filename, "Session clear");
        global.session = {};
    }

    key(name, value) {
        log(__filename, "Session key", name);
        global.session[name] = value;
    }

    set(name, value) {
        log(__filename, "Session set", name);
        let sid = this.cookie.get('sid');

        if(sid){
            let data = global.session[sid._value];

            if(data){
                data[name] = value;
            }else{
                throw T200Error.build(1);
            }
        }else{
            throw T200Error.build(1);
        }
    }

    get(name) {
        log(__filename, "Session get", name);
        let sid = this.cookie.get('sid');

        if(sid){
            let data = global.session[sid._value];

            if(data){
                return data[name];
            }else{
                throw T200Error.build(1);
            }
        }else{
            throw T200Error.build(1);
        }
    }

    build_sid(data) {
        return Date.now();
    }
}

module.exports = T200HttpsSession;