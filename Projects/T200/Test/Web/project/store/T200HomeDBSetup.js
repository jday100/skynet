const T200DBSetup = require('../../library/db/T200DBSetup.js');

class T200HomeDBSetup extends T200DBSetup {
    constructor() {
        super();
        this.database = "web";
        this.user = "web";
        this.password = "web123";
    }
}

module.exports = T200HomeDBSetup;