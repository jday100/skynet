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

    merge_select_by_id() {
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields), T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.EQUAL(this._id, this[this._id])
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

    merge_insert() {
        return T200SQL.INSERT(
            T200SQL.NAME(this._table), 
            T200SQL.FIELDS(this._fields),
            T200SQL.VALUES(this._values)
        );
    }
}

module.exports = T200ModelBase;