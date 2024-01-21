const path = require('path');


class T200Setup {
    constructor() {

    }

    static name = "home";
    static type = "web";
    static project = "../../web/";

    static db_setup = "T200DBsetup.js";
    static web_setup = "T200WebSetup.js";

    static external(file) {
        let name = path.join(__dirname, T200Setup.project);
        return path.join(name, file);
    }
}

module.exports = T200Setup;