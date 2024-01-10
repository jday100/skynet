const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeVisitorModel = require('./T200HomeVisitorModel.js');


class T200Invitation extends T200HomeVisitorModel {
    constructor() {
        super();
        this._table = "invitation";
        this._key = "id";
        this._id = "user_id";

        this.status = 0;
    }

    flash_invitation_fields() {
        this._fields = [
            'id'
        ];
    }

    flash_append_fields() {
        this._fields = [
            'user_id',
            'status',
            'invite',
            'using_time',
            'expiry_time'
        ];
    }

    flash_append_values() {
        this._values = [
            this.user_id,
            this.status,
            this.invite,
            'current_timestamp',
            'current_timestamp'
        ];
    }

}

module.exports = T200Invitation;