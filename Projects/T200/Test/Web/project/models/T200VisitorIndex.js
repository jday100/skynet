const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeVisitorModel = require('./T200HomeVisitorModel.js');


class T200VisitorIndex extends T200HomeVisitorModel {
    constructor() {
        super();
        this._table = "person";
        this._key = "user_id";
    }
}

module.exports = T200VisitorIndex;