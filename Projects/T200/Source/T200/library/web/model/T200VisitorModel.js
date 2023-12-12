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


    flash_register_fields() {
        this._fields = "username, password, email, status";
    }

    flash_register_values() {
        this._values = `'${this.username}', '${this.password}', '${this.email}', 1`;
    }
    
    merge_login() {
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields), 
            T200SQL.FROM(
                T200SQL.ALIAS(this._table, "t1")
            ),
            T200SQL.LEFT(
                T200SQL.ALIAS(this._identity_table, "t2"),
                T200SQL.EQUAL(
                    T200SQL.PREFIX(this._id, "t1"), 
                    T200SQL.PREFIX(this._id, "t2")
                )
            ),
            T200SQL.WHERE(
                T200SQL.AND(
                    T200SQL.AND(
                        T200SQL.EQUAL("username", `'${this.username}'`), 
                        T200SQL.EQUAL("password", `'${this.password}'`)
                    ),
                    T200SQL.EQUAL(
                        T200SQL.PREFIX("status", "t1"), 
                        1
                    )
                )
            )
        );
    }

    flash_login_fields() {
        this._fields = [
            T200SQL.PREFIX("user_id", "t1"),
            T200SQL.PREFIX("status", "t1"),
            T200SQL.PREFIX("city_id", "t2"),
            T200SQL.PREFIX("identity_id", "t1"),
            "username",
            "password",
            T200SQL.PREFIX("flag", "t1")
        ];
    }
    

    /*
    merge_login() {
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

    flash_login_fields() {
        this._fields = [
            "user_id",
            "status",
            "city_id",
            "identity_id",
            "username",
            "password",
            "flag"
        ];
    }
    */

    ///
    merge_admin_login() {
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields), T200SQL.FROM(this._table),
            T200SQL.WHERE(
                //T200SQL.AND(
                    T200SQL.AND(
                        T200SQL.EQUAL("username", `'${this.username}'`), 
                        T200SQL.EQUAL("password", `'${this.password}'`)
                    )//,
                    //T200SQL.EQUAL("status", 1)
                //)
            )
        );
    }

    admin_login_fields() {
        return `user_id, city_id, username`;
    }
}

module.exports = T200VisitorModel;