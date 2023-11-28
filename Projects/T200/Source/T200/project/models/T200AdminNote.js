const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeAdminModel = require('./T200HomeAdminModel.js');


class T200AdminNote extends T200HomeAdminModel {
    constructor() {
        super();
        this._table = "note";
        this._key = "id";

        this.status = 0;
    }


    merge_status_count(value) {
        if(undefined == value){
            return `select count(${this._key}) as total from ${this._table}`;
        }
        return `select count(${this._key}) as total from ${this._table} where status = ${value}`;
    }

    merge_status_paging_test(value) {
        if(undefined == this.status){
            return `select ${this._fields} from ${this._table} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${value}`;
        }
        return `select ${this._fields} from ${this._table} where status = ${this.status} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${value}`;
    }

    merge_status_paging(value) {
        if(undefined == value){
            return `select ${this._fields} from ${this._table} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
        }
        return `select ${this._fields} from ${this._table} where status = ${value} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
    }

    merge_select_by_status(value) {
        return `select ${this._fields} from ${this._table} where status = ${value} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
    }

    merge_status_update() {
        return `update ${this._table} set status = ${this.status} where id in (${this.ids})`;
    }

    
    fields() {
        return "user_id, status, title, content";
    }

    values() {
        return `${this.user_id}, ${this.status}, '${this.title}', '${this.content}'`;
    }

    list_fields() {
        return "id, status, title, create_time";
    }

    fulltext_result_fields() {
        return "id, title, create_time";
    }

    fulltext_fields() {
        return "title, content";
    }
}

module.exports = T200AdminNote;