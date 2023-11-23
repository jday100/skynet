const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200VisitorModel = require('../../library/web/model/T200VisitorModel.js');


class T200HomeVisitorModel extends T200VisitorModel {
    constructor() {
        super();
    }
}

module.exports = T200HomeVisitorModel;