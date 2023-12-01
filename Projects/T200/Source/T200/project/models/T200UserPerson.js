const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeUserModel = require('./T200HomeUserModel.js');


class T200UserPerson extends T200HomeUserModel {
    constructor() {
        super();
        this._table = "person";
        this._key = "user_id";

        this.status = 0;
    }

    profile_fields() {
        return "user_id, region_id, city_id, username, nickname, email, intro, create_time";
    }

    modify_nickname_array() {
        return [
            ['nickname', `'${this.nickname}'`]
        ];
    }

    modify_password_array() {
        return [
            ['password', `'${this.password}'`]
        ];
    }
}

module.exports = T200UserPerson;