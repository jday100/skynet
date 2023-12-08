const { error, log, log_start, log_stop } = require('../library/T200Lib.js');
const T200Error = require('../library/T200Error.js');

const mysql = require('mysql');

const T200Dotter = require('../library/T200Dotter.js');

var dotter = new T200Dotter();
var pool;
var conn;

function connect() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(5);
        pool.getConnection(function(err, result){
            conn = result;
            query1().then(resolve);
        });
    });

    return promise;
}

function disconnect() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(8);
        conn.release();
        return stop().then(resolve);
    });

    return promise;
}

function query1() {
    let promise = new Promise(function(resolve, reject){
         dotter.hit(6);
         conn.query("select * from person");
         execute().then(resolve);
    });

    return promise;
}

function execute() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(7);
        conn.query("select * from person");
        disconnect().then(resolve);
    });

    return promise;
}

function start() {
    let promise = new Promise(function(resolve, reject){
       dotter.hit(4);
       pool = mysql.createPool({
            host: "localhost",
            user: "home",
            password: "home123",
            database: "home",
            port: 3306
       });
       connect().then(resolve);  
    });

    return promise;
}

function stop() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(9);
        setTimeout(() => {
            dotter.hit(10);
            pool.end();
            resolve();
        }, 1000);
    });

    return promise;
}

function dispatcher() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(2);
        done().then(resolve);
    });

    return promise;
}

function done() {
    let promise = new Promise(function(resolve, reject){
        dotter.hit(3);
        start().then(resolve);
    });

    return promise;
}

function run() {
    let promise = new Promise(function(resolve, reject){
         dotter.hit(1);
         dispatcher().then(resolve);
    });

    return promise;
}


log_start(__filename, "test");

run().then(function(){
    dotter.hit(11);
}).finally(function(){
    dotter.hit(12);
    let result = dotter.judge();
    console.log(result);
});

log_stop(__filename, "test");