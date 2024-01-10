const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeUserModel = require('./T200HomeUserModel.js');


class T200UserNote extends T200HomeUserModel {
    constructor() {
        super();
        this._table = "note";
        this._key = "id";
        this._id = "user_id";

        this.status = 0;

        this._person_table = "person";
    }

    flash_content_append_fields() {
        this._fields = [
            'user_id',
            'status',
            'title',
            'content'
        ];
    }

    flash_content_append_values() {
        this._values = [
            this.user_id,
            this.status,
            `'${this.title}'`,
            `'${this.content}'`
        ];
    }

    flash_content_paging_fields() {
        this._fields = [
            'id',
            'title',
            T200SQL.PREFIX('status', 't1'),
            T200SQL.PREFIX('username', 't2'),
            T200SQL.PREFIX('create_time', 't1')            
        ];
    }

    flash_content_fulltext_fields() {
        this._fulltext_fields = [
            'title',
            'content'
        ];
    }

    flash_content_status_update() {
        this._name_value = [
            ['status', this.status]
        ];
    }

    set_item_left() {
        return [
            ['Title', 'title', true, '/content/note/note.html', 'list_title', true, 'id', 'id']
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
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/content/note/remove'],
            ['Publish', 'list_hit_publish', 'form', 'list_box', '/content/note/publish']
        ];
    }

    
    merge_user_paging_where() {
        let where;

        if(undefined == this.status || '' == this.status){
            where = T200SQL.WHERE(
                            T200SQL.AND(
                                T200SQL.EQUAL(
                                    T200SQL.PREFIX(this._id, 't1'), 
                                    this.user_id
                                ),
                                T200SQL.EQUAL(
                                    T200SQL.PREFIX("status", 't2'), 
                                    1
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
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("status", "t2"), 
                                1
                            )
                        )
                    );
        }

        return where;
    }

    merge_user_paging_count() {
        let where = this.merge_user_paging_where();
        return T200SQL.SELECT(
            T200SQL.AS(T200SQL.COUNT(this._key), 'total'),
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
            where
        );
    }

    merge_user_paging_list() {
        let where = this.merge_user_paging_where();
        
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

    merge_user_status_update() {
        return T200SQL.UPDATE(
            T200SQL.NAME(this._table),
            T200SQL.SET(
                T200SQL.NAME_VALUE(this._name_value)
            ),
            T200SQL.WHERE(
                T200SQL.AND(
                    T200SQL.EQUAL(this._id, this.user_id),
                    T200SQL.IN(this._key, this.ids)
                )
            )
        );
    }

    merge_user_fulltext_where() {
        let where;

        if(undefined == this.status || '' == this.status){
            where = T200SQL.WHERE(
                        T200SQL.AND(
                            T200SQL.AND(
                                T200SQL.EQUAL(
                                    T200SQL.PREFIX(this._id, 't1'), 
                                    this.user_id
                                ),
                                T200SQL.EQUAL(
                                    T200SQL.PREFIX("status", 't2'), 
                                    1
                                )
                            ),
                            T200SQL.ALIAS(
                                T200SQL.MATCH(this._fulltext_fields),
                                T200SQL.AGAINST(T200SQL.STRING(this._search))
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
                            T200SQL.AND(
                                T200SQL.EQUAL(
                                    T200SQL.PREFIX("status", "t2"), 
                                    1
                                ),
                                T200SQL.ALIAS(
                                    T200SQL.MATCH(this._fulltext_fields),
                                    T200SQL.AGAINST(T200SQL.STRING(this._search))
                                )
                            )
                        )
                    );
        }

        return where;
    }


    merge_user_fulltext_count() {
        let where = this.merge_user_fulltext_where();
        return T200SQL.SELECT(
            T200SQL.AS(T200SQL.COUNT(this._key), 'total'),
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
            where
        );
    }

    merge_user_fulltext_list() {
        let where = this.merge_user_fulltext_where();
        
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

module.exports = T200UserNote;