const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeUserModel = require('./T200HomeUserModel.js');


class T200UserHouseRent extends T200HomeUserModel {
    constructor() {
        super();
        this._table = "house_rent";
        this._key = "id";
        this._id = "user_id";

        this.city_id = 0;
        this.status = 0;

        this._person_table = "person";
    }

    append_fields() {
        return [
            'user_id',
            'title',
            'content'
        ];
    }

    append_values() {
        return [
            this.user_id,
            `'${this.title}'`,
            `'${this.content}'`
        ];
    }

    content_list_fields() {
        return [
            'id',
            'title',
            T200SQL.PREFIX('status', 't1'),
            T200SQL.PREFIX('create_time', 't1'),
            T200SQL.PREFIX('username', 't2')
        ];
    }

    modify_status_array() {
        return [
            ['status', this.status]
        ];
    }


    /////////////////

    set_item_left() {
        return [
            ['Title', 'title', true, '/content/house/rent.html', 'list_title']
        ];
    }

    set_item_right() {
        return [
            ['Status', 'status', false, '', 'list_status', true, 'id', 'status', 'list_status'],
            ['Username', 'username', true, '', 'list_name', false],
            ['CreateTime', 'create_time', false, '', 'list_time', true, 'time', 'time_title', 'list_time']
        ];
    }

    set_list_buttons() {
        return [
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/content/house/rent/remove'],
            ['Publish', 'list_hit_publish', 'form', 'list_box', '/content/house/rent/publish']
        ];
    }

    merge_fulltext_test(value) {
        if(undefined == this.status || '' == this.status){
            return `select ${this._fields} from ${this._table} t1 inner join person t2 on t1.user_id = t1.user_id where match(${this._search_fields}) against('${this._search}') order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
        }
        return `select ${this._fields} from ${this._table} t1 inner join person t2 on t1.user_id = t1.user_id where match(${this._search_fields}) against('${this._search}') and t1.status = ${this.status} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
    }

    list_status_fields() {
        return "id, t1.status, username, title, t1.create_time";
    }

    merge_status_count(value) {
        if(undefined == value || '' == value){
            return `select count(${this._key}) as total from ${this._table}`;
        }
        return `select count(${this._key}) as total from ${this._table} where status = ${value}`;
    }

    merge_status_paging_test(value) {
        if(undefined == this.status || '' == this.status){
            return `select ${this._fields} from ${this._table} t1 inner join person t2 on t1.user_id = t1.user_id order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
        }
        return `select ${this._fields} from ${this._table} t1 inner join person t2 on t1.user_id = t1.user_id where t1.status = ${this.status} order by ${this._key} ${this._order_direction} limit ${this._page_size} offset ${this._offset}`;
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
        return "id, title, t1.create_time";
    }

    fulltext_fields() {
        return "title, content";
    }


}

module.exports = T200UserHouseRent;