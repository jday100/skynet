const T200Web = require('../../../library/web/T200Web.js');


class T200HomeWeb extends T200Web {
    constructor() {
        super();

        this.html = [
            "/link.html",
            "/form.html"
        ]
    }
}

module.exports = T200HomeWeb;