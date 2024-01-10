const T200Module = require('../../../lib/web/T200Module.js');


class T200LinkModule extends T200Module {
    constructor(page) {
        super(page);
        this.name = "link";        
    }
}

module.exports = T200LinkModule;