const { error, log, log_start, log_stop } = require('../library/T200Lib.js');
const T200Error = require('../library/T200Error.js');

const T200Dotter = require('../library/T200Dotter.js');


function test1() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(1);
        test4().then(function(){
            test5().then(function(){
                test6();
            });
        });
        resolve();
    });

    return promise;
}

function test2() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(2);
        return test7().then(function(){
            return test8().then(function(){
                return test9();
            });
        });
        resolve();
    });

    return promise;
}

function test3() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(3);
        test10();
        test11();
        test12();
        resolve();
    });

    return promise;
}

function test4() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(4);
        test13().then(function(){
            test14().then(function(){
                test15();
            });
        });
        resolve();
    });

    return promise;
}

function test5() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(5);
        test16().then(function(){
            test17().then(function(){
                test18();
            });
        });
        resolve();
    });

    return promise;
}

function test6() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(6);
        test19().then(function(){
            test20().then(function(){
                test21();
            });
        });
        resolve();
    });

    return promise;
}

function test7() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(7);
        return test22().then(function(){
            return test23().then(function(){
                return test24();
            });
        });
        resolve();
    });

    return promise;
}

function test8() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(8);
        return test25().then(function(){
            return test26().then(function(){
                return test27();
            });
        });
        resolve();
    });

    return promise;
}

function test9() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(9);
        return test28().then(function(){
            return test29().then(function(){
                return test30();
            });
        });
        resolve();
    });

    return promise;
}

function test10() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(10);
        test31();
        test32();
        test33();
        resolve();
    });

    return promise;
}

function test11() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(11);
        test34();
        test35();
        test36();
        resolve();
    });

    return promise;
}

function test12() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(12);
        test37();
        test38();
        test39();
        resolve();
    });

    return promise;
}

function test13() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(13);
        setTimeout(function(){
            dotter.hit(41);
        }, 1000);
        resolve();
    });

    return promise;
}

function test14() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(14);
        setTimeout(function(){
            dotter.hit(42);
        }, 1000);
        resolve();
    });

    return promise;
}

function test15() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(15);
        setTimeout(function(){
            dotter.hit(43);
        }, 1000);
        resolve();
    });

    return promise;
}

function test16() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(16);
        setTimeout(function(){
            dotter.hit(44);
        }, 1000);
        resolve();
    });

    return promise;
}

function test17() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(17);
        setTimeout(function(){
            dotter.hit(45);
        }, 1000);
        resolve();
    });

    return promise;
}

function test18() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(18);
        setTimeout(function(){
            dotter.hit(46);
        }, 1000);
        resolve();
    });

    return promise;
}

function test19() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(19);
        setTimeout(function(){
            dotter.hit(47);
        }, 1000);
        resolve();
    });

    return promise;
}

function test20() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(20);
        setTimeout(function(){
            dotter.hit(48);
        }, 1000);
        resolve();
    });

    return promise;
}

function test21() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(21);
        setTimeout(function(){
            dotter.hit(49);
        }, 1000);
        resolve();
    });

    return promise;
}

function test22() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(22);
        setTimeout(function(){
            dotter.hit(50);
        }, 1000);
        resolve();
    });

    return promise;
}

function test23() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(23);
        setTimeout(function(){
            dotter.hit(51);
        }, 1000);
        resolve();
    });

    return promise;
}

function test24() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(24);
        setTimeout(function(){
            dotter.hit(52);
        }, 1000);
        resolve();
    });

    return promise;
}

function test25() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(25);
        setTimeout(function(){
            dotter.hit(53);
        }, 1000);
        resolve();
    });

    return promise;
}

function test26() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(26);
        setTimeout(function(){
            dotter.hit(54);
        }, 1000);
        resolve();
    });

    return promise;
}

function test27() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(27);
        setTimeout(function(){
            dotter.hit(55);
        }, 1000);
        resolve();
    });

    return promise;
}

function test28() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(28);
        setTimeout(function(){
            dotter.hit(56);
        }, 1000);
        resolve();
    });

    return promise;
}

function test29() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(29);
        setTimeout(function(){
            dotter.hit(57);
        }, 1000);
        resolve();
    });

    return promise;
}

function test30() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(30);
        setTimeout(function(){
            dotter.hit(58);
        }, 1000);
        resolve();
    });

    return promise;
}

function test31() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(31);
        setTimeout(function(){
            dotter.hit(59);
        }, 1000);
        resolve();
    });

    return promise;
}

function test32() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(32);
        setTimeout(function(){
            dotter.hit(60);
        }, 1000);
        resolve();
    });

    return promise;
}

function test33() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(33);
        setTimeout(function(){
            dotter.hit(61);
        }, 1000);
        resolve();
    });

    return promise;
}

function test34() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(34);
        setTimeout(function(){
            dotter.hit(62);
        }, 1000);
        resolve();
    });

    return promise;
}

function test35() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(35);
        setTimeout(function(){
            dotter.hit(63);
        }, 1000);
        resolve();
    });

    return promise;
}

function test36() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(36);
        setTimeout(function(){
            dotter.hit(64);
        }, 1000);
        resolve();
    });

    return promise;
}

function test37() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(37);
        setTimeout(function(){
            dotter.hit(65);
        }, 1000);
        resolve();
    });

    return promise;
}

function test38() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(38);
        setTimeout(function(){
            dotter.hit(66);
        }, 1000);
        resolve();
    });

    return promise;
}

function test39() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(39);
        setTimeout(function(){
            dotter.hit(67);
        }, 1000);
        resolve();
    });

    return promise;
}

function test40() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(40);
        setTimeout(function(){
            dotter.hit(68);
        }, 1000);
        resolve();
    });

    return promise;
}



log_start(__filename, "test promise");

var dotter = new T200Dotter();

test1().then(function(){
    return test2();
}).then(function(){
    return test3();
}).finally(function(){
    let result = dotter.judge();
    console.log("Test Promise result: " + result);
});

log_stop(__filename, "test promise");