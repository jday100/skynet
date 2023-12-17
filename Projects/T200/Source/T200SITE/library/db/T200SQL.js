const { log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');


class T200SQL {
    constructor() {

    }

    static CREATE(value) {
        return `create ${value}`;
    }

    static DROP(value) {
        return `drop ${value}`;
    }

    static ALTER(value) {
        return `alter ${value}`;
    }

    static SELECT(value) {
        return `select ${value}`;
    }

    static INSERT(value) {
        return `insert ${value}`;
    }

    static DELETE(value) {
        return `delete ${value}`;
    }

    static UPDATE(value) {
        return `update ${value}`;
    }


    ///
    static INNER(value) {
        return `inner join ${value}`;
    }

    static LEFT(value) {
        return `left join ${value}`;
    }

    static RIGHT(value) {
        return `right join ${value}`;
    }

    static ALIAS(name, value) {
        return `${name} ${value}`;
    }

    static PREFIX(name, value) {
        return `${value}.${name}`;
    }

    ///

}

module.exports = T200SQL;