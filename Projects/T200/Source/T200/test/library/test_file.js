const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const T200File = require('../../library/fs/T200File.js');
const T200Path = require('../../library/fs/T200Path.js');

log_start(__filename, "test fs");

var name = "home/index.html";
var real = T200Path.join_root(name);

log(__filename, `test ${name}`);
T200File.exists(real).then(function(){
    log(__filename, `${name} exists`);
    return error();
}, function(err){
    log(__filename, `${name} not exists`);
}).then(function(){
    name = "home/login.html";
    real = T200Path.join_root(name);

    log(__filename, `test ${name}`);

    return T200File.exists(real);
}, function(err){
    return error();
}).then(function(){
    log(__filename, `${name} exists`);
    return T200File.load(real);
}, function(err){
    return error();
}).then(function(data){
    log(__filename, "test fs success", data);
}, function(err){
    log(__filename, "test fs failure");
});

log_stop(__filename, "test fs");