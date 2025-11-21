const {log, log_start, log_stop} = require(`./library/T200Base.js`);
const T200Source = require("./source/T200Source.js");

log_start(__filename, "SourceScanner");

let     path    = T200Source.get_path();
let     type    = T200Source.get_type();

T200Source.execute(path, type);

log_stop(__filename, "SourceScanner");