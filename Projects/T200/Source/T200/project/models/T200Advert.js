const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200SQL = require('../../library/db/T200SQL.js');

const T200HomeVisitorModel = require('./T200HomeVisitorModel.js');


class T200Advert extends T200HomeVisitorModel {
    constructor() {
        super();
        this._table = "advert";
        this._key = "id";

        this.status = 0;
    }

    flash_append_fields() {
        this._fields = [
            'status',
            'name',
            'content'
        ];
    }

    flash_append_values() {
        this._values = [
            this.status,
            `'${this.name}'`,
            `'${this.content}'`
        ];
    }

    fields() {
        return "user_id, city_id, status, title, content";
    }

    values() {
        return `${this.user_id}, ${this.city_id}, ${this.status}, '${this.title}', '${this.content}'`;
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

module.exports = T200Advert;