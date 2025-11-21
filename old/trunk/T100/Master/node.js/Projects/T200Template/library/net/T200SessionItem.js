const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');


class T200SessionItem {
    constructor() {
        this._secret = "";
        this._name = "";
        this._resave = false;
        this._save_uninitialized = false;
        this._cookie = "";
    }
}

module.exports = T200SessionItem;