const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeVisitorModel = require('./T200HomeVisitorModel.js');


class T200Identity extends T200HomeVisitorModel {
    constructor() {
        super();
        this._table = "identity";
        this._key = "user_id";

        this.status = 0;
    }

    flash_append_fields() {
        this._fields = [
            'user_id',
            'status',
            'nickname',
            'intro',
            'flag'
        ];
    }

    flash_append_values() {
        this._values = [
            this.user_id,
            this.status,
            `'${this.nickname}'`,
            `'${this.intro}'`,
            this.flag
        ];
    }

}

module.exports = T200Identity;