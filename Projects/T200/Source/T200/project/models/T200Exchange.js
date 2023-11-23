const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeVisitorModel = require('./T200HomeVisitorModel.js');


class T200Exchange extends T200HomeVisitorModel {
    constructor() {
        super();
        this._table = "exchange";
        this._key = "id";
    }

    list_fields() {
        return "title, create_time";
    }

}

module.exports = T200Exchange;