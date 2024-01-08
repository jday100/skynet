const T200Module = require('../../../lib/web/T200Module.js');


class T200NavModule extends T200Module {
    constructor(page) {
        super(page);
        this.name = "nav";        
    }
}

module.exports = T200NavModule;