const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200VisitorModel = require('../../library/web/model/T200VisitorModel.js');


class T200HomeVisitorModel extends T200VisitorModel {
    constructor() {
        super();
    }

    merge_single_list() {
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.EQUAL("status", this.status)
            ),
            T200SQL.ORDER(
                T200SQL.DESC(this._key)
            ),
            T200SQL.LIMIT(this._page_size)
        );
    }

    merge_multiple_list() {
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(
                T200SQL.ALIAS(this._table, "t1")
            ),
            T200SQL.INNER(
                T200SQL.ALIAS(this._identity_table, "t2"),
                T200SQL.EQUAL(
                    T200SQL.PREFIX(this._id, "t1"),
                    T200SQL.PREFIX(this._id, "t2")
                )
            ),
            T200SQL.WHERE(
                T200SQL.AND(
                    T200SQL.AND(
                        T200SQL.EQUAL(
                            T200SQL.PREFIX("status", "t1"),
                            1
                        ),
                        T200SQL.EQUAL(
                            T200SQL.PREFIX("status", "t2"),
                            1
                        )
                    ),
                    T200SQL.EQUAL(
                        "parent_id",
                        0
                    )
                )
            ),
            T200SQL.ORDER(
                T200SQL.DESC(T200SQL.PREFIX("id", "t1"))
            ),
            T200SQL.LIMIT(this._page_size)
        );
    }
}

module.exports = T200HomeVisitorModel;