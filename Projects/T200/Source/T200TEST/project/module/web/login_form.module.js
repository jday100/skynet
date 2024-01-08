const T200Module = require('../../../lib/web/T200Module.js');


class T200LoginModule extends T200Module {
    constructor(page) {
        super(page);
        this.name = "login_form";
    }
}

module.exports = T200LoginModule;