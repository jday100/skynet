const path = require('path');


class T200Setup {
    constructor() {

    }

    static type = "web";
    static project = "../../web/";

    static external(file) {
        return path.join(T200Setup.project, file);
    }
}

module.exports = T200Setup;