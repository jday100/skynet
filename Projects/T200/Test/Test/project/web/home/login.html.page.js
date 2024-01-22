const T200Page = require('../../../library/web/T200Page.js');


class T200LoginPage extends T200Page {
    constructor(name) {
        super(name);

        this.defines = [
            "person"
        ];

        this.modules = [
            "login_form"
        ];
    }


}

module.exports = T200LoginPage;