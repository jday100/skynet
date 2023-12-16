const T200Error = require('./T200Error.js');


class T200Math {
    constructor() {

    }

    static random(min, max) {
        let range = max - min;
        let value = Math.random();

        return min + Math.round(value * range);
    }
}

module.exports = T200Math;