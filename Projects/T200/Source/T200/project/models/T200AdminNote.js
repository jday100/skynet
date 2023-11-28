const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeAdminModel = require('./T200HomeAdminModel.js');


class T200AdminNote extends T200HomeAdminModel {
    constructor() {
        super();
        this._table = "note";
        this._key = "id";

        this.status = 0;
    }


    merge_status_update() {
        return `update ${this._table} set status = ${this.status} where id in (${this.ids})`;
    }

    
    fields() {
        return "user_id, status, title, content";
    }

    values() {
        return `${this.user_id}, ${this.status}, '${this.title}', '${this.content}'`;
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

module.exports = T200AdminNote;