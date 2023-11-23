const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200UserBiz = require('../../library/web/biz/T200UserBiz.js');
const T200HomeStore = require('../store/T200HomeStore.js');


class T200HomeUserBiz extends T200UserBiz {
    constructor() {
        super();
        this.store = new T200HomeStore();
    }
}

module.exports = T200HomeUserBiz;