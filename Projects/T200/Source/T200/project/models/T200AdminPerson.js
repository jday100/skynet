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
            T200SQL.AS('user_id', 'id'),
            'city_id',
            'status',
            'username',
            'nickname',
            'email',
            'create_time'
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
    
    merge_admin_fulltext_count() {
        return T200SQL.SELECT(
            T200SQL.AS(T200SQL.COUNT(this._key), 'total'),
            T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.AND(
                    T200SQL.EQUAL(this._id, this.user_id),
                    T200SQL.ALIAS(
                        T200SQL.MATCH(this._search_fields),
                        T200SQL.AGAINST(this.search)
                    )
                )
            )
        );
    }

    merge_admin_fulltext_list() {
        let where;

        if(undefined == this.status || '' == this.status){
            where = T200SQL.WHERE(
                        T200SQL.AND(
                            T200SQL.EQUAL(
                                T200SQL.PREFIX(this._id, 't1'), 
                                this.user_id
                            ),
                            T200SQL.ALIAS(
                                T200SQL.MATCH(this._search_fields),
                                T200SQL.AGAINST(this.search)
                            )
                        )                        
                    );
        }else{
            where = T200SQL.WHERE(
                        T200SQL.AND(
                            T200SQL.AND(
                                T200SQL.EQUAL(
                                    T200SQL.PREFIX("status", "t1"), 
                                    this.status
                                    ),
                                T200SQL.EQUAL(
                                    T200SQL.PREFIX(this._id, 't1'), 
                                    this.user_id
                                    )
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
    
}

module.exports = T200AdminPerson;