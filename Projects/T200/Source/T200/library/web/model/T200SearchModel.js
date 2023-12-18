const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200SQL = require('../../db/T200SQL.js');
const T200PagingModel = require('./T200PagingModel.js');


class T200SearchModel extends T200PagingModel {
    constructor() {
        super();
        this._search = "";
    }

    merge_fulltext_where() {
        let where;

        if(undefined == this.status || '' == this.status){
            where = T200SQL.WHERE(
                        T200SQL.AND(
                            T200SQL.EQUAL("status", 1),
                            T200SQL.ALIAS(
                                T200SQL.MATCH(this._fulltext_fields),
                                T200SQL.AGAINST(T200SQL.STRING(this._search))
                            )
                        )
                    );
        }else{
            where = T200SQL.WHERE(
                        T200SQL.AND(
                            T200SQL.EQUAL(
                                "status",
                                this.status
                            ),
                            T200SQL.ALIAS(
                                T200SQL.MATCH(this._fulltext_fields),
                                T200SQL.AGAINST(T200SQL.STRING(this._search))
                            )                            
                        )
                    );
        }

        return where;
    }


    merge_fulltext_count() {
        let where = this.merge_fulltext_where();
        return T200SQL.SELECT(
            T200SQL.AS(T200SQL.COUNT(this._key), 'total'),
            T200SQL.FROM(this._table),
            where
        );
    }

    merge_fulltext_list() {
        let where = this.merge_fulltext_where();
        
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(this._table),
            where,
            T200SQL.ORDER(T200SQL.DESC(this._key)),
            T200SQL.LIMIT(this._page_size),
            T200SQL.OFFSET(this._offset)
        );
    }
}

module.exports = T200SearchModel;