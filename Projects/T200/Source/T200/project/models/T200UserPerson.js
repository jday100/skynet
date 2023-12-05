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

    flash_profile_fields() {
        this._fields = "user_id, continent_id, region_id, city_id, status, username, nickname, email, gender, year, month, day, intro, create_time, modify_time, login_time, ip";
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

    modify_region_array() {
        return [
            //['region_id', `${this.region_id}`],
            ['city_id', `${this.city_id}`]
        ];
    }

    modify_intro_array() {
        return [
            ['intro', `'${this.intro}'`]
        ];
    }

}

module.exports = T200UserPerson;