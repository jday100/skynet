const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeAdminModel = require('./T200HomeAdminModel.js');


class T200AdminNote extends T200HomeAdminModel {
    constructor() {
        super();
        this._table = "note";
        this._key = "id";
        this._id = "user_id";

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

    
    admin_list_fields() {
        return [
            'id',
            'title',
            T200SQL.PREFIX('status', 't1'),
            T200SQL.PREFIX('create_time', 't1'),
            T200SQL.PREFIX('username', 't2')
        ];
    }

    admin_fulltext_fields() {
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
            ['Title', 'title', true, '/admin/note/note.html', 'list_title']
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
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/admin/note/remove'],
            ['Approve', 'list_hit_approve', 'form', 'list_box', '/admin/note/approve']
        ];
    }
}

module.exports = T200AdminNote;