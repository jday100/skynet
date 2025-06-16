const { log, log_start, log_stop } = require('./library/T200Lib.js');
const T200Template = require(`./template/T200Template.js`);

log_start(__filename, "T200Template");

T200Template.execute();

log_stop(__filename, "T200Template");