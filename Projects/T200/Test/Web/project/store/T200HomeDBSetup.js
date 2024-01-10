const T200DBSetup = require('../../library/db/T200DBSetup.js');

class T200HomeDBSetup extends T200DBSetup {
    constructor() {
        super();
        this.database = "home";
        this.user = "home";
        this.password = "home123";
    }
}

module.exports = T200HomeDBSetup;