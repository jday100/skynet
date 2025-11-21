const {log, log_start, log_stop} = require(`./library/T200Base.js`);
const T200Sort = require("./sort/T200Sort.js");

log_start(__filename, "Sort");

T200Sort.execute();

log_stop(__filename, "Sort");