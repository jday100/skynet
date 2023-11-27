
const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeUserModel = require('./T200HomeUserModel.js');


class T200UserTrading extends T200HomeUserModel {
    constructor() {
        super();
        this._table = "";
        this._key = "id";

        this.city_id = 0;
        this.status = 0;
    }

    fields() {
        return "user_id, city_id, status, title, content";
    }

    values() {
        return `${this.user_id}, ${this.city_id}, ${this.status}, '${this.title}', '${this.content}'`;
    }

    list_fields() {
        return "id, title, create_time";
    }

    
    fulltext_result_fields() {
        return "id, title, create_time";
    }

    fulltext_fields() {
        return "title, content";
    }

}

module.exports = T200UserTrading;