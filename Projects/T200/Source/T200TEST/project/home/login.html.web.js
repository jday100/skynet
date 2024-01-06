const T200WebBase = require('../../lib/web/T200WebBase.js');


class T200LoginWeb extends T200WebBase {
    constructor() {
        super();

        this.objects = [
            "person"
        ];

        this.modules = [
            "nav",
            "channel",
            "login_form"
        ];
    }
}

module.exports = T200LoginWeb;