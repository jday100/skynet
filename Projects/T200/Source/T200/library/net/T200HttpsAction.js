const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');


class T200HttpsAction {
    constructor() {
        this.get = {};
        this.post = {};
    }

    use_get(action, callback) {
        log(__filename, "use_get", action);
        this.get[action] = callback;
    }

    use_post(action, callback) {
        log(__filename, "use_post", action);
        this.post[action] = callback;
    }
}

module.exports = T200HttpsAction;