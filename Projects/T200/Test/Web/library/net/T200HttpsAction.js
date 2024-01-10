const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');


class T200HttpsAction {
    constructor() {
        this.get = {};
        this.post = {};
        this.socket = {};
    }

    use_get(action, callback) {
        log(__filename, "use_get", action);
        this.get[action] = callback;
    }

    use_post(action, callback) {
        log(__filename, "use_post", action);
        this.post[action] = callback;
    }

    use_socket(action, callback) {
        log(__filename, "use_socket", action);
        this.socket[action] = callback;
    }
}

module.exports = T200HttpsAction;