const T200Module = require('../../../lib/web/T200Module.js');


class T200RegisterModule extends T200Module {
    constructor(page) {
        super(page);
        this.name = "register_form";
    }
}

module.exports = T200RegisterModule;