const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeAdminModel = require('./T200HomeAdminModel.js');


class T200AdminInvitation extends T200HomeAdminModel {
    constructor() {
        super();
        this._table = "invitation";
        this._key = "id";
        this._id = "user_id";

        this.status = 0;

        this._person_table = "person";
    }
    
    flash_admin_paging_fields() {
        this._fields = [
            'id',
            'invite',
            T200SQL.PREFIX('status', 't1'),
            T200SQL.PREFIX('username', 't2'),
            T200SQL.PREFIX('create_time', 't1')            
        ];
    }

    flash_admin_status_update() {
        this._name_value = [
            ['status', this.status]
        ];
    }

    set_item_left() {
        return [
            ['Invite', 'invite', true, '/admin/invitation/invite.html', 'list_title']
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
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/admin/invitation/remove'],
            ['Approve', 'list_hit_approve', 'form', 'list_box', '/admin/invitation/approve']
        ];
    }
}

module.exports = T200AdminInvitation;