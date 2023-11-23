const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');


class T200CookieItem {
    constructor(name, value) {
        this._name = name;
        this._value = value;
        this._expires = 0;
        this._max_age = 0;
        this._domain = "";
        this._path = "";
        this._http_only = false;
        this._secure = false;

        //
        this._expires = Date.now() + global.setup.https.cookie_live_time;
    }

    to_string() {
        return `${this._name}=${this._value}; Expires=${this._expires}`;
    }

    parse(msg) {
        log(__filename, "cookie parse", msg);
        
        if(undefined == msg){
            throw T200Error.build();
        }

        msg.split(';').forEach(item => {
            let values = item.split('=');
            this.#classify(values[0].trim(), (values[1] || '').trim());
        });
    }

    #classify(name, value) {
        switch(name.toLowerCase()){
            case 'name':
                this._name = value;
                break;
            case 'expires':
                this._expires = value;
                break;
            case 'maxage':
                this._max_age = value;
                break;
            case 'domain':
                this._domain = value;
                break;
            case 'path':
                this._path = value;
                break;
            case 'httponly':
                this._httponly = value;
                break;
            case 'secure':
                this._secure = value;
                break;
            default:
                throw T200Error.build();
        }
    }
}

module.exports = T200CookieItem;