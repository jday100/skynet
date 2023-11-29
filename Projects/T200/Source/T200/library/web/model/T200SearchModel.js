const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200PagingModel = require('./T200PagingModel.js');


class T200SearchModel extends T200PagingModel {
    constructor() {
        super();
        this._search = "";
    }

    merge_fulltext_count(status, value) {
        return `select count(${this._key}) as total from ${this._table} where match(${this._search_fields}) against('${value}')`;
    }

    merge_fulltext_paging(status, value) {
        return `select ${this._fields} from ${this._table} where match(${this._search_fields}) against('${value}') order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
    }
}

module.exports = T200SearchModel;