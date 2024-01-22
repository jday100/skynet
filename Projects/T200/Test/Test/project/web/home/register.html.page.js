const T200Page = require('../../../library/web/T200Page.js');


class T200RegisterPage extends T200Page {
    constructor(name) {
        super(name);

        this.defines = [
            "person"
        ];

        this.modules = [
            "register_form"
        ];
    }


}

module.exports = T200RegisterPage;