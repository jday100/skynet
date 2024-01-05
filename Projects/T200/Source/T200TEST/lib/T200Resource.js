const path = require('path');


class T200Resource {
    constructor() {

    }

    static merge_test_case(dir) {
        return path.join(__dirname, `../case/web/${dir}`);
    }

    static merge_case(file) {
        return path.join(__dirname, `../case/web/${file}`);
    }

    static merge_case_dir(dir) {
        return path.join(__dirname, `../case/web/${dir}`);
    }

    static merge_web(file) {
        return path.join(__dirname, `../project/home/${file}.web.js`);
    }

    static merge_object_define(file) {
        return path.join(__dirname, `../project/define/object/${file}.define`);
    }

    static merge_web_define(file) {
        return path.join(__dirname, `../project/define/web/${file}.define`);
    }
}

module.exports = T200Resource;