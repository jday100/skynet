const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeVisitorModel = require('./T200HomeVisitorModel.js');


class T200Person extends T200HomeVisitorModel {
    constructor() {
        super();
        this._table = "person";
        this._key = "user_id";

        this.status = 0;
        this.city_id = 0;
    }

    fields() {
        return "city_id, status, username, password, email";
    }

    values() {
        return `${this.city_id}, ${this.status}, '${this.username}', '${this.password}', '${this.email}'`;
    }

    list_fields() {
        return "city_id, username, email, create_time";
    }

}

module.exports = T200Person;