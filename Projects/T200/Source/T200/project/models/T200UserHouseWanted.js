const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeUserModel = require('./T200HomeUserModel.js');


class T200UserHouseWanted extends T200HomeUserModel {
    constructor() {
        super();
        this._table = "house_wanted";
        this._key = "id";
        this._user_id = "user_id";
        this._id = "identity_id";

        this.city_id = 0;
        this.status = 0;

        this._person_table = "person";
        this._identity_table = "identity";
    }



    flash_content_append_fields() {
        this._fields = [
            'user_id',
            'status',
            'identity_id',
            'city_id',
            'type_long',
            'type_short',
            'title',
            'content'
        ];
    }

    flash_content_append_values() {
        this._values = [
            this.user_id,
            this.status,
            this.identity_id,
            this.city_id,
            this.type_long,
            this.type_short,
            `'${this.title}'`,
            `'${this.content}'`
        ];
    }

    flash_reply_fields() {
        this._fields = [
            'user_id',
            'identity_id',
            'parent_id',
            'parent_type',
            'city_id',
            'status',
            'title',
            'content'
        ];
    }

    flash_reply_values() {
        this._values = [
            this.user_id,
            this.identity_id,
            this.parent_id,
            1,
            this.city_id,
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
            T200SQL.PREFIX('nickname', 't2'),
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

    flash_content_parent_update() {
        this._name_value = [
            ['parent_id', this.parent_id]
        ];
    }

    set_item_left() {
        return [
            ['Title', 'title', true, '/content/house/wanted.html', 'list_title']
        ];
    }

    set_item_right() {
        return [
            ['Status', 'status', false, '', 'list_status', true, 'id', 'status', 'list_status'],
            ['Nickname', 'nickname', true, '', 'list_name', false],
            ['CreateTime', 'create_time', false, '', 'list_time', true, 'time', 'time_title', 'list_time']
        ];
    }

    set_list_buttons() {
        return [
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/content/house/wanted/remove'],
            ['Publish', 'list_hit_publish', 'form', 'list_box', '/content/house/wanted/publish']
        ];
    }

    merge_user_paging_long_list() {
        let where;

        where = T200SQL.WHERE(
                    T200SQL.AND(
                        T200SQL.AND(
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("status", 't1'), 
                                1
                            ),
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("status", 't2'), 
                                1
                            )
                        ),
                        T200SQL.EQUAL(
                            "type_long",
                            1
                        )
                    )  
                );

        
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

    merge_user_paging_short_list() {
        let where;

        where = T200SQL.WHERE(
                    T200SQL.AND(
                        T200SQL.AND(
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("status", 't1'), 
                                1
                            ),
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("status", 't2'), 
                                1
                            )
                        ),
                        T200SQL.EQUAL(
                            "type_short",
                            1
                        )
                    )  
                );

        
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

module.exports = T200UserHouseWanted;