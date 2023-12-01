const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200SQL = require('../../db/T200SQL.js');
const T200SearchModel = require('./T200SearchModel.js');


class T200VisitorModel extends T200SearchModel {
    constructor() {
        super();

    }

    merge_register() {
        return T200SQL.INSERT(
            T200SQL.NAME(this._table), T200SQL.FIELDS(this._fields),
            T200SQL.VALUES(this._values)
        );
    }

    register_fields() {
        return `username, password, email`;
    }

    register_values() {
        return `'${this.username}', '${this.password}', '${this.email}'`;
    }
    
    merge_login() {
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields), T200SQL.FROM(this._table),
            T200SQL.WHERE(
                //T200SQL.AND(
                    T200SQL.AND(
                        T200SQL.EQUAL("username", `'${this.username}'`), 
                        T200SQL.EQUAL("password", `'${this.password}'`)
                    //),
                    //T200SQL.EQUAL("status", 1)
                )
            )
        );
    }

    login_fields() {
        return `user_id, region_id, city_id, username, password`;
    }

    ///
    merge_admin_login() {
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields), T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.AND(
                    T200SQL.AND(
                        T200SQL.EQUAL("username", `'${this.username}'`), 
                        T200SQL.EQUAL("password", `'${this.password}'`)
                    ),
                    T200SQL.EQUAL("status", 1)
                )
            )
        );
    }

    admin_login_fields() {
        return `user_id, city_id, username`;
    }
}

module.exports = T200VisitorModel;