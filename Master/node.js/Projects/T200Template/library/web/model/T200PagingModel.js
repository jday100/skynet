const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200SQL = require('../../db/T200SQL.js');
const T200ModelBase = require('./T200ModelBase.js');


class T200PagingModel extends T200ModelBase {
    constructor() {
        super();

        this._folio_size = 5;
        this._page_size = 10;
        this._offset = 0;
        this._order_field = "";
        this._order_direction = "";
        //
        this._page;
        this._total = 0;
    }

    merge_list() {
        return `select ${this._fields} from ${this._table} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
    }

    merge_city_list() {
        return `select ${this._fields} from ${this._table} where city_id = ${this.city_id} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
    }

    merge_count() {
        return T200SQL.SELECT(
            T200SQL.AS(T200SQL.COUNT(this._key), 'total'),
            T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.EQUAL("status", 1)
            )
        );
    }

    merge_paging() {
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.EQUAL("status", 1)
            ),
            T200SQL.ORDER(T200SQL.DESC(this._key)),
            T200SQL.LIMIT(this._page_size),
            T200SQL.OFFSET(this._offset)
        );
    }
}

module.exports = T200PagingModel;