const path = require('path');


class T200Resource {
    constructor() {

    }

    static merge_test_case(dir) {
        let file = `../case/web${dir}test_case.js`;
        return path.join(__dirname, file);
    }

    static merge_test_unit(name) {
        let file = `../case/web${name}.case.js`;
        return path.join(__dirname, file);
    }

    static merge_web_page(name) {
        let file = `../project/home${name}.page.js`;
        return path.join(__dirname, file);
    }

    static merge_web_module(name) {
        let file = `../project/module/web/${name}.module.js`;
        return path.join(__dirname, file);
    }

    static merge_web_define(name) {
        let file = `../project/define/web/${name}.define`;
        return path.join(__dirname, file);
    }
}

module.exports = T200Resource;