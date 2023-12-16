const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeAdminModel = require('./T200HomeAdminModel.js');


class T200AdminPerson extends T200HomeAdminModel {
    constructor() {
        super();
        this._table = "person";
        this._key = "user_id";

        this.status = 0;
    }

    flash_admin_append_fields() {
        this._fields = [
            'user_id',
            'title',
            'content'
        ];
    }

    flash_admin_append_values() {
        this._values = [
            this.user_id,
            `'${this.title}'`,
            `'${this.content}'`
        ];
    }

    flash_admin_paging_fields() {
        this._fields = [
            T200SQL.AS('user_id', 'id'),
            'status',
            'username',
            'nickname',
            'email',
            'create_time'
        ];
    }

    admin_person_fulltext_fields() {
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

    set_item_left() {
        return [
            ['Username', 'username', true, '/admin/person/person.html', 'list_name']
        ];
    }

    set_item_right() {
        return [
            ['Status', 'status', false, '', 'list_status', true, 'id', 'status', 'list_status'],
            ['CreateTime', 'create_time', false, '', 'list_time', true, 'time', 'time_title', 'list_time']
        ];
    }

    set_list_buttons() {
        return [
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/admin/person/remove'],
            ['Approve', 'list_hit_approve', 'form', 'list_box', '/admin/person/approve']
        ];
    }
    
    merge_admin_person_paging_count() {
        return T200SQL.SELECT(
            T200SQL.AS(T200SQL.COUNT(this._key), 'total'),
            T200SQL.FROM(this._table)//,
            //T200SQL.WHERE(T200SQL.EQUAL(this._id, this.user_id))
        );
    }

    
    merge_admin_person_paging_list() {
        let where;

        if(undefined == this.status || '' == this.status){
            where = "";
        }else{
            where = T200SQL.WHERE(
                        T200SQL.EQUAL(
                            'status',
                            this.status
                        )
                    );
        }
        
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(this._table),
            where,
            T200SQL.ORDER(T200SQL.DESC(this._key)),
            T200SQL.LIMIT(this._page_size),
            T200SQL.OFFSET(this._offset)
        );
    }
    
    merge_admin_person_fulltext_count() {
        return T200SQL.SELECT(
            T200SQL.AS(T200SQL.COUNT(this._key), 'total'),
            T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.ALIAS(
                    T200SQL.MATCH(this._search_fields),
                    T200SQL.AGAINST(this.search)
                )
            )
        );
    }

    merge_admin_person_fulltext_list() {
        let where;

        if(undefined == this.status || '' == this.status){
            where = T200SQL.WHERE(
                        T200SQL.ALIAS(
                            T200SQL.MATCH(this._search_fields),
                            T200SQL.AGAINST(this.search)
                        )
                    );
        }else{
            where = T200SQL.WHERE(
                        T200SQL.AND(
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("status", "t1"), 
                                this.status
                                ),
                            T200SQL.ALIAS(
                                T200SQL.MATCH(this._search_fields),
                                T200SQL.AGAINST(this.search)
                            )
                        )
                    );
        }
        
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(
                T200SQL.ALIAS(this._table, "t1")
                ),
            T200SQL.INNER(
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

    merge_admin_person_search_count() {
        return T200SQL.SELECT(
            T200SQL.AS(T200SQL.COUNT(this._key), 'total'),
            T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.EQUAL(
                    'username',
                    `'${this.username}'`
                )
            )
        );
    }

    merge_admin_person_search_list() {
        let where;

        if(undefined == this.status || '' == this.status){
            where = T200SQL.WHERE(
                        T200SQL.EQUAL(
                            "username",
                            `'${this.username}'`
                        )
                    );
        }else{
            where = T200SQL.WHERE(
                        T200SQL.AND(
                            T200SQL.EQUAL(
                                "status",
                                this.status
                                ),
                            T200SQL.EQUAL(
                                "username",
                                `'${this.username}'`
                            )
                        )
                    );
        }
        
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(
                this._table
                ),
                where,
            T200SQL.ORDER(T200SQL.DESC(this._key)),
            T200SQL.LIMIT(this._page_size),
            T200SQL.OFFSET(this._offset)
        );
    }
    
}

module.exports = T200AdminPerson;