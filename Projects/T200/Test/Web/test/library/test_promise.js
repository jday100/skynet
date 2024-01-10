const { error, log, log_start, log_stop } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Dotter = require('../../library/T200Dotter.js');



function step1(dotter) {
    let promise = new Promise(function(resolve, reject){
        dotter.success(5);
        resolve();
    });

    return promise;
}

function step2(dotter) {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(4);
        step1(dotter).then(resolve, reject);
    });

    return promise;
}

function step3(dotter) {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(3);
        //step2(dotter).then(resolve, reject);
        step2(dotter).then(function(){
            step1(dotter);
        });
    });

    return promise;
}

function step4(dotter) {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(2);
        step3(dotter).then(resolve, reject);
    });

    return promise;
}

function step5(dotter) {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(1);
        step4(dotter).then(resolve, reject);
    });

    return promise;
}




log_start(__filename, "test promise");


let dotter = new T200Dotter();

step5(dotter).then(function(){
    dotter.hit(6);
}, function(){

}).finally(function(){
    dotter.hit(7);

    log(__filename, "result: ", dotter.judge());
});

step1(dotter);
step2(dotter);
step3(dotter);
step4(dotter);
step5(dotter);

log_stop(__filename, "test promise");