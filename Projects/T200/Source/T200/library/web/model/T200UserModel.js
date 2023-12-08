const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200SQL = require('../../db/T200SQL.js');

const T200ForumModel = require('./T200ForumModel.js');


class T200UserModel extends T200ForumModel {
    constructor() {
        super();
    }

    flash_user_board_fields() {
        this._fields = [
            "id",
            "nickname",
            "intro",
            "title",
            "content",
            "parent_id",
            T200SQL.PREFIX("create_time", "t1")
        ];
    }

    flash_logout_values() {
        this._name_value = [
            [this._key, this._key]
        ];
    }

    merge_user_logout() {
        return T200SQL.UPDATE(
            T200SQL.NAME(this._table),
            T200SQL.SET(
                T200SQL.NAME_VALUE(this._name_value)
            ),
            T200SQL.WHERE(
                T200SQL.EQUAL(this._key, this.user_id)
            )
        );
    }

    merge_user_insert() {
        return this.merge_insert();
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
                                T200SQL.AGAINST(this._search)
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
                                    T200SQL.AGAINST(this._search)
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


    merge_user_board_where() {
        let where;

        if(undefined == this.status || '' == this.status){
            where = T200SQL.WHERE(
                        T200SQL.AND(
                            T200SQL.AND(T200SQL.EQUAL(
                                T200SQL.PREFIX("status", 't1'), 
                                    1
                                ),
                                T200SQL.EQUAL(
                                    T200SQL.PREFIX("status", 't2'), 
                                    1
                                )
                            ),
                            T200SQL.OR(
                                T200SQL.EQUAL(
                                    this._key,
                                    this[this._key]
                                ),
                                T200SQL.EQUAL(
                                    "parent_id",
                                    this[this._key]
                                )
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
                                    T200SQL.PREFIX("status", "t2"), 
                                    1
                                )
                            ),
                            T200SQL.EQUAL(
                                "parent_id",
                                this.parent_id
                            )
                        )
                    );
        }

        return where;
    }

    merge_user_board_count() {
        let where = this.merge_user_board_where();
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

    merge_user_board_list() {
        let where = this.merge_user_board_where();
        
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
            T200SQL.ORDER(this._key),
            T200SQL.LIMIT(this._page_size),
            T200SQL.OFFSET(this._offset)
        );
    }

}

module.exports = T200UserModel;