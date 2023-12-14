const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200UserModel = require('../../library/web/model/T200UserModel.js');


class T200HomeUserModel extends T200UserModel {
    constructor() {
        super();
    }

    list_fields() {
        return [
            "id",
            "title",
            T200SQL.PREFIX("create_time", "t1")
        ];
    }

    
    merge_user_paging_type_count() {
        return T200SQL.SELECT(
            T200SQL.AS(
                T200SQL.COUNT(this._key), 
                'total'
            ),
            T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.AND(
                    T200SQL.EQUAL("status", 1),
                    T200SQL.EQUAL(1, 1)
                )
            )
        );
    }

    merge_user_paging_type_list() {
        let where;

        where = T200SQL.WHERE(
                    T200SQL.EQUAL(
                        T200SQL.PREFIX("status", 't1'), 
                        1
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

    merge_user_paging_city_list() {
        let where;

        where = T200SQL.WHERE(
                    T200SQL.AND(
                        T200SQL.AND(
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("status", 't2'), 
                                1
                            ),
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("status", 't1'), 
                                1
                            )
                        ),
                        T200SQL.AND(
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("parent_type", 't1'), 
                                0
                            ),
                            T200SQL.EQUAL(
                                T200SQL.PREFIX("city_id", 't1'), 
                                this.city_id
                            )
                        )
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
            T200SQL.ORDER(T200SQL.DESC(this._key)),
            T200SQL.LIMIT(this._page_size),
            T200SQL.OFFSET(this._offset)
        );
    }
    
}

module.exports = T200HomeUserModel;