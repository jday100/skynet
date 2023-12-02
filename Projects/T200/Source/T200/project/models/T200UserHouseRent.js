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

    content_fulltext_fields() {
        return [
            'title',
            'content'
        ];
    }

    modify_status_array() {
        return [
            ['status', this.status]
        ];
    }

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

}

module.exports = T200UserHouseRent;