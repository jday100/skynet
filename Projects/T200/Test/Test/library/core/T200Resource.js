const path = require('path');


class T200Resource {
    constructor() {

    }

    static merge_file(category, project, source) {
        let file = `../../project/${category}/${project}/${source}`;
        return path.join(__dirname, file);
    }

    static merge_case(category, project, source) {
        let file = `../../project/${category}/${project}/${source}.case.js`;
        return path.join(__dirname, file);
    }

    static merge_web_define(project, source) {
        let file = `../../project/web/${project}/${source}.define`;
        return path.join(__dirname, file);
    }

    static merge_web_page(project, source) {
        let file = `../../project/web/${project}/${source}.page.js`;
        return path.join(__dirname, file);
    }

    static merge_web_module(project, source) {
        let file = `../../project/web/${project}/${source}.module.js`;
        return path.join(__dirname, file);
    }

    static merge_object_define(name) {
        let file = `../../project/define/${name}.define`;
        return path.join(__dirname, file);
    }
}

module.exports = T200Resource;