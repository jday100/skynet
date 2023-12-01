const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200SQL = require('../../db/T200SQL.js');


class T200ModelBase {
    constructor() {
        this._table = "";
        this._key = "";
        this._id = "";
        //
        this._fields = "";
        this._values = "";
    }

    merge_select_by_key() {
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields), T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.EQUAL(this._key, this[this._key])
            )
        );
    }

    merge_update_by_key() {
        return T200SQL.UPDATE(
            T200SQL.NAME(this._table), 
            T200SQL.SET(
                T200SQL.NAME_VALUE(this._name_value)
            ),
            T200SQL.WHERE(
                T200SQL.EQUAL(this._key, this[this._key])
            )
        );
    }
}

module.exports = T200ModelBase;