const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200UserModel = require('../../library/web/model/T200UserModel.js');


class T200HomeUserModel extends T200UserModel {
    constructor() {
        super();
    }
}

module.exports = T200HomeUserModel;