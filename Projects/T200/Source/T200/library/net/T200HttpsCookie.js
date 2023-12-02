const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const T200CookieItem = require('./T200CookieItem.js');


class T200HttpsCookie {
    constructor(req, res) {
        this.req = req;
        this.res = res;
    }

    load() {
        log(__filename, "Cookie load");

        let self = this;
        this.cookies = {};

        if(this.req){
            if(this.req.headers){
                if(this.req.headers.cookie){
                    /*
                    this.cookies = {};
                    this.req.headers.cookie.split(';').forEach(item => {
                        let values = item.split('=');
                        self.cookies[ values[0].trim() ] = (values[1] || '').trim();
                    });
                    */
                   
                   self.#parse(self.req.headers.cookie);
                }else{

                }
            }else{
                throw(T200Error.build(1));
            }
        }else{  
            throw(T200Error.build(1));
        }
    }

    set(name, value) {
        log(__filename, "Cookie set", name);
        //this.res.setHeader('Set-Cookie', `${name}=${value};`);
        let cookie = new T200CookieItem(name, value);
        let msg = cookie.to_string();
        this.res.setHeader('Set-Cookie', msg);
    }

    get(name) {
        log(__filename, "Cookie get", name);
        return this.cookies[name];
    }

    set_item(item) {
        let msg = item.to_string();
        this.res.setHeader('Set-Cookie', msg);
    }


    #parse(msg) {
        log(__filename, "cookie parse", msg);
        
        let self = this;
        if(undefined == msg){
            throw T200Error.build();
        }

        msg.split(';').forEach(item => {
            let cookie = new T200CookieItem();
            let values = item.split('=');
            self.#classify(cookie, values[0].trim(), (values[1] || '').trim());
            self.cookies[cookie._name] = cookie;
        });
        
    }

    #classify(cookie, name, value) {
        switch(name.toLowerCase()){
            case 'expires':
                cookie._expires = value;
                break;
            case 'maxage':
                cookie._max_age = value;
                break;
            case 'domain':
                cookie._domain = value;
                break;
            case 'path':
                cookie._path = value;
                break;
            case 'httponly':
                cookie._httponly = value;
                break;
            case 'secure':
                cookie._secure = value;
                break;
            default:
                cookie._name = name;
                cookie._value = value;
        }
    }
}

module.exports = T200HttpsCookie;