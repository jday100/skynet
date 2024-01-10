const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeVisitorModel = require('./T200HomeVisitorModel.js');


class T200Notice extends T200HomeVisitorModel {
    constructor() {
        super();
        this._table = "notice";
        this._key = "id";

        this.status = 0;
    }

    flash_append_fields() {
        this._fields = [
            'user_id',
            'status',
            'title',
            'content'
        ];
    }

    flash_append_values() {
        this._values = [
            this.user_id,
            this.status,
            `'${this.title}'`,
            `'${this.content}'`
        ];
    }

    flash_paging_fields() {
        this._fields = [
            'id',
            'title',
            'create_time'         
        ];
    }

    flash_fulltext_fields() {
        this._fulltext_fields = [
            'title',
            'content'
        ];
    }

    fields() {
        return "user_id, status, title, content";
    }

    values() {
        return `${this.user_id}, ${this.status}, '${this.title}', '${this.content}'`;
    }

    merge_update_status(){
        return ``;
    }

    view_fields() {
        return "title, content, create_time";
    }


    list_fields() {
        return "id, status, title, create_time";
    }

    fulltext_result_fields() {
        return "id, title, create_time";
    }

    fulltext_fields() {
        return "title, content";
    }

}

module.exports = T200Notice;