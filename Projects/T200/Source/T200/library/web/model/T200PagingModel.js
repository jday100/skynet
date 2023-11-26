const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

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
        return `select count(${this._key}) as total from ${this._table}`;
    }

    merge_paging() {
        return `select ${this._fields} from ${this._table} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
    }
}

module.exports = T200PagingModel;