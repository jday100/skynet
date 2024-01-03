const path = require('path');


class T200Resource {
    constructor() {

    }

    static merge_case(file) {
        return path.join(__dirname, `../case/web/${file}.case.js`);
    }

    static merge_web(file) {
        return path.join(__dirname, `../project/home/${file}.web.js`);
    }

    static merge_define(file) {
        return path.join(__dirname, `../project/define/${file}.define`);
    }
}

module.exports = T200Resource;