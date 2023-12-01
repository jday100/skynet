const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200SearchModel = require('./T200SearchModel.js');


class T200ForumModel extends T200SearchModel {
    constructor() {
        super();

    }

    board_fields() {
        return `id, title, content, parent_id, create_time`;
    }

    merge_board_count(value) {
        return `select count(${this._key}) as total from ${this._table} where ${this._key} = ${value} or parent_id = ${value}`;
    }

    merge_board_list(value) {
        return `select ${this._fields} from ${this._table} where ${this._key} = ${this.id} or parent_id = ${this.id} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
    }
}

module.exports = T200ForumModel;