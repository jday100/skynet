const T200Page = require('../../lib/web/T200Page.js');


class T200LinkPage extends T200Page {
    constructor(name) {
        super(name);

        this.object_defines = [

        ];

        this.module_defines = [
            "link"
        ];

        this.objects = new Array();
        this.modules = new Array();
    }

}

module.exports = T200LinkPage;