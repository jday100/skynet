const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeVisitorModel = require('./T200HomeVisitorModel.js');


class T200Visitor extends T200HomeVisitorModel {
    constructor() {
        super();
        this._table = "person";
        this._key = "user_id";
        this._id = "identity_id";

        this._identity_table = "identity";
    }

    flash_visitor_fields() {
        this._fields = [
            'user_id'
        ];
    }
}

module.exports = T200Visitor;