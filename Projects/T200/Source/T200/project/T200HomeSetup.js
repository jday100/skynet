const T200HttpsSetup = require('../library/net/T200HttpsSetup.js');

class T200HomeSetup extends T200HttpsSetup {
    constructor() {
        super();

        this.port = 8888;
        this.index = "index.html,index.htm";
    }
}

module.exports = T200HomeSetup;