const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const { SELECT, FROM, WHERE, ORDER, DESC, LIMIT, OFFSET, EQUAL } = require('../../library/db/T200SQL.js');



let sql = SELECT('*', FROM('person'), WHERE(EQUAL('user_id', 1)), ORDER(DESC('user_id')), LIMIT(10), OFFSET(0));

console.log(sql);

sql = SELECT('*', FROM('person'), WHERE(EQUAL('user_id', 1)), ORDER(DESC('user_id')), LIMIT(10));

console.log(sql);

sql = SELECT('*', FROM('person'));

console.log(sql);