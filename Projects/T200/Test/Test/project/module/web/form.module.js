const T200Module = require('../../../lib/web/T200Module.js');


class T200FormModule extends T200Module {
    constructor(page) {
        super(page);
        this.name = "form";
    }
}

module.exports = T200FormModule;