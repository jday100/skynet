const path = require('path');


class T200Resource {
    constructor() {

    }

    static merge_file(category, project, source) {
        let file = `../../project/${category}/${project}/${source}`;
        return path.join(__dirname, file);
    }
}

module.exports = T200Resource;