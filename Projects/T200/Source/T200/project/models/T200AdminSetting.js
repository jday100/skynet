const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeAdminModel = require('./T200HomeAdminModel.js');


class T200AdminSetting extends T200HomeAdminModel {
    constructor() {
        super();
        this._table = "setting";
        this._key = "id";
        this._id = "user_id";

        this.status = 0;

        this._person_table = "person";
    }

    flash_admin_list_fields() {
        this._fields = [
            'id',
            'setting_id',
            'name',
            'content',
            'status'
        ];
    }

    flash_admin_append_fields() {
        this._fields = [
            'setting_id',
            'status',
            'name',
            'content'
        ];
    }

    flash_admin_append_values() {
        this._values = [
            this.setting_id,
            this.status,
            `'${this.name}'`,
            `'${this.content}'`
        ];
    }

    
    flash_admin_paging_fields() {
        this._fields = [
            'id',
            'title',
            T200SQL.PREFIX('status', 't1'),
            T200SQL.PREFIX('username', 't2'),
            T200SQL.PREFIX('create_time', 't1')            
        ];
    }

    flash_admin_fulltext_fields() {
        this._fulltext_fields = [
            'title',
            'content'
        ];
    }

    flash_admin_status_update() {
        this._name_value = [
            ['status', this.status]
        ];
    }

    flash_admin_content_update() {
        this._name_value = [
            ['content', `'${this.content}'`]
        ];
    }

    merge_admin_setting_list() {
        let where;

        where = T200SQL.WHERE(
                    T200SQL.EQUAL(
                        'status',
                        1
                    )
                );

        
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(this._table),
            where,
            T200SQL.ORDER(T200SQL.DESC(this._key)),
            T200SQL.LIMIT(this._page_size),
            T200SQL.OFFSET(this._offset)
        );
    }

    merge_admin_setting_by_id() {
        let where;

        where = T200SQL.WHERE(
                    T200SQL.AND(
                        T200SQL.EQUAL(
                            'status',
                            1
                        ),
                        T200SQL.EQUAL(
                            'setting_id',
                            this.setting_id
                        )
                    )                    
                );

        
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(this._table),
            where
        );
    }

}

module.exports = T200AdminSetting;