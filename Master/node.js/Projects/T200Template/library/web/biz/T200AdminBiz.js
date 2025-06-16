const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200ForumBiz = require('./T200ForumBiz.js');


class T200AdminBiz extends T200ForumBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }
}

module.exports = T200AdminBiz;