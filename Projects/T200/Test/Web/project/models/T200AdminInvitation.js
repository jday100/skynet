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
            T200SQL.PREFIX('invite', 't1'),
            T200SQL.PREFIX('status', 't1'),
            T200SQL.PREFIX('user_id', 't2'),
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
            ['Invite', 'invite', false, '/admin/invitation/invite.html', 'list_title']
        ];
    }

    set_item_right() {
        return [
            ['Status', 'status', false, '', 'list_status', true, 'id', 'status', 'list_status'],
            ['Username', 'username', true, '/admin/person/person.html', 'list_name', true, 'id', 'user_id'],
            ['CreateTime', 'create_time', false, '', 'list_time', true, 'time', 'time_title', 'list_time']
        ];
    }

    set_list_buttons() {
        return [
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/admin/invitation/remove'],
            ['Approve', 'list_hit_approve', 'form', 'list_box', '/admin/invitation/approve']
        ];
    }

    merge_admin_paging_where() {
        let where;

        if(undefined == this.status || '' == this.status){
            where = T200SQL.WHERE(
                        T200SQL.EQUAL(
                            T200SQL.PREFIX("status", 't2'), 
                            1
                        )
                    );
        }else{
            where = T200SQL.WHERE(
                        T200SQL.AND(
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("status", "t1"), 
                                this.status
                            ),
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("status", "t2"), 
                                1
                            )
                        )
                    );
        }

        return where;
    }

    merge_admin_paging_count() {
        let where = this.merge_admin_paging_where();
        return T200SQL.SELECT(
            T200SQL.AS(T200SQL.COUNT(this._key), 'total'),
            T200SQL.FROM(
                T200SQL.ALIAS(this._table, "t1")
                ),
            T200SQL.LEFT(
                T200SQL.ALIAS(this._person_table, "t2"), 
                T200SQL.EQUAL(
                    T200SQL.PREFIX(this._id, "t1"), 
                    T200SQL.PREFIX(this._id, "t2")
                )
            ),
            where
        );
    }

    
    merge_admin_paging_list() {
        let where = this.merge_admin_paging_where();
        
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(
                T200SQL.ALIAS(this._table, "t1")
                ),
            T200SQL.LEFT(
                T200SQL.ALIAS(this._person_table, "t2"), 
                T200SQL.EQUAL(
                    T200SQL.PREFIX(this._id, "t1"), 
                    T200SQL.PREFIX(this._id, "t2")
                )
            ),
            where,
            T200SQL.ORDER(T200SQL.DESC(this._key)),
            T200SQL.LIMIT(this._page_size),
            T200SQL.OFFSET(this._offset)
        );
    }
}

module.exports = T200AdminInvitation;