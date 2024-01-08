const T200Module = require('../../../lib/web/T200Module.js');


class T200ChannelModule extends T200Module {
    constructor(page) {
        super(page);
        this.name = "channel";
    }
}

module.exports = T200ChannelModule;