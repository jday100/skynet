const path = require('path');


class T200Resource {
    constructor() {

    }

    static merge_web_case(dir) {
        let file = `../case/web${dir}test_case.js`;
        return path.join(__dirname, file);
    }

    static merge_web_unit(project, source) {
        let file = `../case/web/${project}${source}.case.js`;
        return path.join(__dirname, file);
    }

    static merge_web_page(project, source) {
        let file = `../project/web/${project}/pages/${source}.page.js`;
        return path.join(__dirname, file);
    }

    static merge_web_module(project, source) {
        let file = `../project/web/${project}/modules/${source}.module.js`;
        return path.join(__dirname, file);
    }

    static merge_web_define(project, source) {
        let file = `../project/define/web/${project}/${source}.define`;
        return path.join(__dirname, file);
    }

    static merge_web_flow(name) {
        let file = `../project/define/flow/web/${name}.flow`;
        return path.join(__dirname, file);
    }

    static merge_object_define(name) {
        let file = `../project/define/object/${name}.define`;
        return path.join(__dirname, file);
    }

    static merge_flow_parser(name) {
        let file = `../project/flow/web/${name}.parser.js`;
        return path.join(__dirname, file);
    }
}

module.exports = T200Resource;