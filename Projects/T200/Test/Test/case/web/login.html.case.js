const T200Case = require('../../lib/T200Case.js');


class T200LoginCase extends T200Case {
    constructor() {
        super();
        this.url = "/login.html";
    }
}

module.exports = T200LoginCase;