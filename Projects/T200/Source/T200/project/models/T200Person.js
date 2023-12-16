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

    flash_append_fields() {
        this._fields = [
            'status',
            'username',
            'password',
            'nickname',
            'email',
            'gender',
            'year',
            'month',
            'day',
            'intro',
            'flag',
            'create_time',
            'login_time'
        ];
    }

    flash_append_values() {
        this._values = [
            this.status,
            `'${this.username}'`,
            `'${this.password}'`,
            `'${this.nickname}'`,
            `'${this.email}'`,
            this.gender,
            this.year,
            this.month,
            this.day,
            `'${this.intro}'`,
            this.flag,
            'current_timestamp',
            'current_timestamp'
        ];
    }

}

module.exports = T200Person;