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

    flash_content_profile_init_update() {
        this._name_value = [
            ['continent_id', this.continent_id],
            ['continent_name', `'${this.continent_name}'`],
            ['country_id', this.country_id],
            ['country_name', `'${this.country_name}'`],
            ['gender', this.gender],
            ['year', this.year],
            ['month', this.month],
            ['day', this.day],
            ['intro', `'${this.intro}'`],
            ['flag', 1]
        ];
    }

    flash_content_profile_email_update() {
        this._name_value = [
            ['email', `'${this.email}'`]
        ];
    }

    flash_content_profile_nationality_update() {
        this._name_value = [
            ['continent_id', this.continent_id],
            ['continent_name', `'${this.continent_name}'`],
            ['country_id', this.country_id],
            ['country_name', `'${this.country}'`]
        ];
    }

    flash_content_profile_identity_update() {
        this._name_value = [
            ['identity_id', this.identity_id]
        ];
    }

    ////////////////////////

    flash_profile_fields() {
        this._fields = [
            'user_id',
            'continent_id',
            'country_id',
            'status', 
            'username',
            'email',
            'gender',
            'year',
            'month',
            'day',
            'intro',
            'create_time',
            'modify_time',
            'login_time',
            'ip'
        ];
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

    flash_content_nickname_update() {
        this._name_value = [
            ['nickname_id', this.nickname_id],
            ['nickname', `'${this.nickname}'`]
        ];
    }

}

module.exports = T200UserPerson;