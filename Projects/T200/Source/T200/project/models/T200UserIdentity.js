const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeUserModel = require('./T200HomeUserModel.js');


class T200UserIdentity extends T200HomeUserModel {
    constructor() {
        super();
        this._table = "identity";
        this._key = "identity_id";
        this._id = "user_id";

        this.status = 0;

        this._person_table = "person";
    }


    flash_content_identity_fields() {
        this._fields = [
            'identity_id',
            'user_id',
            'continent_id',
            'region_id',
            'city_id',
            'nickname',
            'intro'
        ];
    }

    flash_content_search_fields() {
        this._fields = [
            'nickname_id'
        ];
    }

    flash_content_append_fields() {
        this._fields = [
            'user_id',
            'status',
            'continent_id',
            'region_id',
            'city_id',
            'nickname',
            'ip'
        ];
    }

    flash_content_append_values() {
        this._values = [
            this.user_id,
            this.status,
            this.continent_id,
            this.region_id,
            this.city_id,
            `'${this.nickname}'`,
            `'${this.ip}'`
        ];
    }

    flash_content_paging_fields() {
        this._fields = [
            'nickname_id',
            'nickname',
            T200SQL.PREFIX('status', 't1'),
            T200SQL.PREFIX('username', 't2'),
            T200SQL.PREFIX('create_time', 't1')            
        ];
    }

    flash_content_fulltext_fields() {
        this._fulltext_fields = [
            'nickname'
        ];
    }

    flash_content_status_update() {
        this._name_value = [
            ['status', this.status]
        ];
    }

    flash_content_identity_location_update() {
        this._name_value = [
            ['continent_id', this.continent_id],
            ['continent_name', `'${this.continent_name}'`],
            ['region_id', this.region_id],
            ['region_name', `'${this.region_name}'`],
            ['city_id', this.city_id],
            ['city_name', `'${this.city_name}'`]
        ];
    }

    flash_content_identity_intro_update() {
        this._name_value = [
            ['intro', `'${this.intro}'`]
        ];
    }

    set_item_left() {
        return [
            ['Title', 'title', true, '/content/note/note.html', 'list_title']
        ];
    }

    set_item_right() {
        return [
            ['Status', 'status', false, '', 'list_status', true, 'id', 'status', 'list_status'],
            ['Username', 'username', true, '', 'list_name', false],
            ['CreateTime', 'create_time', false, '', 'list_time', true, 'time', 'time_title', 'list_time']
        ];
    }

    set_list_buttons() {
        return [
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/content/note/remove'],
            ['Publish', 'list_hit_publish', 'form', 'list_box', '/content/note/publish']
        ];
    }

    merge_content_status_search() {
        return T200SQL.SELECT(
            T200SQL.FIELDS(this._fields),
            T200SQL.FROM(this._table),
            T200SQL.WHERE(
                T200SQL.AND(
                    T200SQL.EQUAL(
                        "nickname",
                        this.nickname
                    ),
                    T200SQL.EQUAL(
                        "status",
                        0
                    )
                )
            )
        );
    }

}

module.exports = T200UserIdentity;