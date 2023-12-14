const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeUserModel = require('./T200HomeUserModel.js');


class T200UserJobRecruit extends T200HomeUserModel {
    constructor() {
        super();
        this._table = "job_recruit";
        this._key = "id";
        this._user_id = "user_id";
        this._id = "identity_id";

        this.city_id = 0;
        this.status = 0;

        this._person_table = "person";
        this._identity_table = "identity";
    }



    flash_content_append_fields() {
        this._fields = [
            'user_id',
            'status',
            'identity_id',
            'city_id',
            'title',
            'content'
        ];
    }

    flash_content_append_values() {
        this._values = [
            this.user_id,
            this.status,
            this.identity_id,
            this.city_id,
            `'${this.title}'`,
            `'${this.content}'`
        ];
    }

    flash_reply_fields() {
        this._fields = [
            'user_id',
            'identity_id',
            'parent_id',
            'parent_type',
            'city_id',
            'status',
            'title',
            'content'
        ];
    }

    flash_reply_values() {
        this._values = [
            this.user_id,
            this.identity_id,
            this.parent_id,
            1,
            this.city_id,
            this.status,
            `'${this.title}'`,
            `'${this.content}'`
        ];
    }

    flash_content_paging_fields() {
        this._fields = [
            'id',
            'title',
            T200SQL.PREFIX('status', 't1'),            
            T200SQL.PREFIX('nickname', 't2'),
            T200SQL.PREFIX('create_time', 't1')
        ];
    }

    flash_content_fulltext_fields() {
        this._fulltext_fields = [
            'title',
            'content'
        ];
    }

    flash_content_status_update() {
        this._name_value = [
            ['status', this.status]
        ];
    }

    flash_content_parent_update() {
        this._name_value = [
            ['parent_id', this.parent_id]
        ];
    }

    set_item_left() {
        return [
            ['Title', 'title', true, '/content/job/recruit.html', 'list_title']
        ];
    }

    set_item_right() {
        return [
            ['Status', 'status', false, '', 'list_status', true, 'id', 'status', 'list_status'],
            ['Nickname', 'nickname', true, '', 'list_name', false],
            ['CreateTime', 'create_time', false, '', 'list_time', true, 'time', 'time_title', 'list_time']
        ];
    }

    set_list_buttons() {
        return [
            ['Delete', 'list_hit_delete', 'form', 'list_box', '/content/job/recruit/remove'],
            ['Publish', 'list_hit_publish', 'form', 'list_box', '/content/job/recruit/publish']
        ];
    }

}

module.exports = T200UserJobRecruit;