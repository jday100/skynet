const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200AdminModel = require('../../library/web/model/T200AdminModel.js');


class T200HomeAdminModel extends T200AdminModel {
    constructor() {
        super();
    }
}

module.exports = T200HomeAdminModel;