const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const T200File = require('../../library/fs/T200File.js');
const T200Path = require('../../library/fs/T200Path.js');

log_start(__filename, "test path");

var name = "home";
var real = T200Path.join_root(name);

log(__filename, `test path ${name}`);
T200Path.is_dir(real).then(function(result){
    if(result){
        log(__filename, `${name} is directory`);
    }else{
        log(__filename, `${name} is not directory`);
        return error();
    }
}, function(){
    return error();
}).then(function(){
    name = "home/login.html";
    real = T200Path.join_root(name);
    log(__filename, `test path ${name}`);
    return T200Path.is_dir(real);
}, function(){
    return error();
}).then(function(result){
    if(result){
        log(__filename, `${name} is directory`);
        return error();
    }else{
        log(__filename, `${name} is not directory`);
    }

}, function(){
    return error();
}).then(function(){
    log(__filename, "test path success");
}, function(){
    log(__filename, "test path failure");
});

log_stop(__filename, "test path");