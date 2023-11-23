const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');


class T200ModelBase {
    constructor() {
        this._table = "";
        this._key = "";
        this._id = "";
        //
        this._fields = "";
        this._values = "";
    }

    merge_insert() {
        return `insert into ${this._table} (${this._fields}) values (${this._values})`;
    }

    merge_select_by_key(value) {
        return `select ${this._fields} from ${this._table} where ${this._key} = ${value} order by ${this._key}`;
    }
}

module.exports = T200ModelBase;