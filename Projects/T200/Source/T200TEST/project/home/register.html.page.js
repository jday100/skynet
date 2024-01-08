const T200Page = require('../../lib/web/T200Page.js');


class T200RegisterPage extends T200Page {
    constructor(name) {
        super(name);

        this.object_defines = [
            "person"
        ];

        this.module_defines = [
            "nav",
            "channel",
            "register_form"
        ];

        this.objects = new Array();
        this.modules = new Array();
    }
}

module.exports = T200RegisterPage;