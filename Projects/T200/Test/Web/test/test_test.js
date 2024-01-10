const { error, log, log_start, log_stop } = require('../library/T200Lib.js');
const T200Error = require('../library/T200Error.js');

const T200Dotter = require('../library/T200Dotter.js');

function test1() {
    let promise = new Promise(function(resolve){
        dotter.hit(1);
        test2();
        resolve();
    });

    return promise;
}

function test2() {
    let promise = new Promise(function(resolve){
        dotter.hit(2);
        test3();
        resolve();
    });

    return promise;
}


function test3() {
    let promise = new Promise(function(resolve){
        dotter.hit(3);
        test4();
        resolve();
    });

    return promise;
}

function test4() {
    let promise = new Promise(function(resolve){
        dotter.hit(4);
        test5();
        resolve();
    });

    return promise;
}


function test5() {
    let promise = new Promise(function(resolve){
        dotter.hit(5);
        test6();
        resolve();
    });

    return promise;
}


function test6() {
    let promise = new Promise(function(resolve){
        dotter.hit(6);
        test7();
        resolve();
    });

    return promise;
}


function test7() {
    let promise = new Promise(function(resolve){
        dotter.hit(7);
        test8();
        resolve();
    });

    return promise;
}


function test8() {
    let promise = new Promise(function(resolve){
        dotter.hit(8);
        test9();
        resolve();
    });

    return promise;
}



function test9() {
    let promise = new Promise(function(resolve){
        dotter.hit(9);

        setTimeout(() => {
            dotter.hit(10);
        }, 1000);
        resolve();
    });

    return promise;
}

var dotter = new T200Dotter();

log_start(__filename, "test");

test1();

log_stop(__filename, "test");