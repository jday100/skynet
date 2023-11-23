const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200SearchModel = require('./T200SearchModel.js');


class T200VisitorModel extends T200SearchModel {
    constructor() {
        super();

    }

    fields() {
        return `username, password, email`;
    }

    values() {
        return `'${this.username}', '${this.password}', '${this.email}'`;
    }

    merge_register() {
        return this.merge_insert();
    }
    
    merge_login() {
        return `select ${this._key}, username from ${this._table} where username = '${this.username}' and password = '${this.password}'`;
    }

    merge_login_update() {
        return `update ${this._table} set username = '${this.username}' where username = '${this.username}'`;
    }
}

module.exports = T200VisitorModel;