const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeUserModel = require('./T200HomeUserModel.js');


class T200UserFollow extends T200HomeUserModel {
    constructor() {
        super();
        this._table = "follow";
        this._key = "id";
        this._user_id = "user_id";
        this._id = "identity_id";

        this.status = 0;

        this._person_table = "person";
        this._identity_table = "identity";
    }


    flash_content_append_fields() {
        this._fields = [
            'user_id',
            'identity_id'
        ];
    }

    flash_content_append_values() {
        this._values = [
            this.user_id,
            this.identity_id
        ];
    }

    flash_user_list_fields() {
        this._fields = [
            T200SQL.PREFIX('user_id', 't1'),
            T200SQL.PREFIX('identity_id', 't1'),
            'nickname',
            'intro',
            T200SQL.PREFIX('create_time', 't1')
        ];
    }

    flash_visitor_paging_fields() {
        this._fields = [
            'id',
            'title',
            T200SQL.PREFIX('status', 't1'),
            T200SQL.PREFIX('identity_id', 't2'),
            T200SQL.PREFIX('nickname', 't2'),
            T200SQL.PREFIX('create_time', 't1')            
        ];
    }

    flash_visitor_fulltext_fields() {
        this._fulltext_fields = [
            'title',
            'content'
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
            'name',
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

    flash_content_parent_update() {
        this._name_value = [
            ['parent_id', this.parent_id]
        ];
    }

    set_item_left() {
        return [
            ['Name', 'name', true, '/exchange/exchange.html', 'list_title', true, 'id', 'id']
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
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/content/exchange/remove'],
            ['Publish', 'list_hit_publish', 'form', 'list_box', '/content/exchange/publish']
        ];
    }

    merge_user_list() {
        let where;

        where = T200SQL.WHERE(
                    T200SQL.AND(
                        T200SQL.EQUAL(
                            T200SQL.PREFIX("status", 't2'), 
                            1
                        ),
                        T200SQL.EQUAL(
                            T200SQL.PREFIX("user_id", 't1'), 
                            this.user_id
                        )

                        /*T200SQL.EQUAL(
                            T200SQL.PREFIX("status", 't1'), 
                            1
                        )
                    ),
                    T200SQL.AND(
                        T200SQL.EQUAL(
                            T200SQL.PREFIX("user_id", 't1'), 
                            this.user_id
                        ),
                        T200SQL.EQUAL(
                            T200SQL.PREFIX("city_id", 't1'), 
                            this.city_id
                        )*/
                    )                 
                );

        
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(
                T200SQL.ALIAS(this._table, "t1")
                ),
            T200SQL.INNER(
                T200SQL.ALIAS(this._identity_table, "t2"), 
                T200SQL.EQUAL(
                    T200SQL.PREFIX(this._id, "t1"), 
                    T200SQL.PREFIX(this._id, "t2")
                )
            ),
            where,
            T200SQL.ORDER(T200SQL.DESC(this._key))
        );
    }

}

module.exports = T200UserFollow;