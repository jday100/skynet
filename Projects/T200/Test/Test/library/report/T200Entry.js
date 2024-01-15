const T200Vessel = require('../T200Vessel.js');


class T200Entry {
    constructor(name) {
        this.name = name;
        this.values = new T200Vessel();
    }
}

module.exports = T200Entry;