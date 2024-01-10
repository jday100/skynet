const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const T200SQL = require('../../library/db/T200SQL.js');


let sql = T200SQL.SELECT(T200SQL.FIELDS("*"), T200SQL.FROM("person"), 
    T200SQL.WHERE(T200SQL.EQUAL("user_id", 1)), T200SQL.ORDER(T200SQL.DESC("user_id")),
    T200SQL.LIMIT(10), T200SQL.OFFSET(0));

console.log(sql);


if(sql == "select * from person where user_id = 1  order by user_id desc  limit 10 offset 0 "){

}else{

}


/*
let sql = SELECT('*', FROM('person'), WHERE(EQUAL('user_id', 1)), ORDER(DESC('user_id')), LIMIT(10), OFFSET(0));

console.log(sql);

sql = SELECT('*', FROM('person'), WHERE(EQUAL('user_id', 1)), ORDER(DESC('user_id')), LIMIT(10));

console.log(sql);

sql = SELECT('*', FROM('person'));

console.log(sql);
*/