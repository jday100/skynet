const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200VisitorBiz = require('../../library/web/biz/T200VisitorBiz.js');
const T200HomeStore = require('../store/T200HomeStore.js');


class T200HomeVisitorBiz extends T200VisitorBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
        this.store = new T200HomeStore();
    }
}

module.exports = T200HomeVisitorBiz;