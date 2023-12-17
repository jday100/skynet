const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeVisitorModel = require('./T200HomeVisitorModel.js');


class T200Exchange extends T200HomeVisitorModel {
    constructor() {
        super();
        this._table = "exchange";
        this._key = "id";
        this._id = "identity_id";

        this.status = 0;

        this._person_table = "person";
        this._identity_table = "identity";
    }

    flash_append_fields() {
        this._fields = [
            'user_id',
            'identity_id',
            'status',
            'parent_type',
            'parent_id',
            'title',
            'content'
        ];
    }

    flash_append_values() {
        this._values = [
            this.user_id,
            this.identity_id,
            this.status,
            this.parent_type,
            this.parent_id,
            `'${this.title}'`,
            `'${this.content}'`
        ];
    }


    fields() {
        return "user_id, status, title, content";
    }

    values() {
        return `${this.user_id}, ${this.status}, '${this.title}', '${this.content}'`;
    }

    list_fields() {
        return [
            "id",
            "title",
            "nickname",
            T200SQL.PREFIX("create_time", "t1")
        ];
    }

    fulltext_result_fields() {
        return "id, title, create_time";
    }

    fulltext_fields() {
        return "title, content";
    }

}

module.exports = T200Exchange;