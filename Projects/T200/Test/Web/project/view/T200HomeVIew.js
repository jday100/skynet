const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200ViewBase = require('../../library/web/view/T200ViewBase.js');


class T200HomeView extends T200ViewBase {
    constructor(resource) {
        super(resource);
    }
}

module.exports = T200HomeView;