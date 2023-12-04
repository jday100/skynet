const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeVisitorBiz = require('./T200HomeVisitorBiz.js');

const T200House = require('../models/T200House.js');
const T200Job = require('../models/T200Job.js');
const T200Trading = require('../models/T200Trading.js');
const T200Exchange = require('../models/T200Exchange.js');


class T200HomeCityIndex extends T200HomeVisitorBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    load_index(id) {
        log(__filename, "load");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let data = {};

            self.load_house_rents(id, data).then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.load_house_wanted(id, data);
            }, function(){
                return error();
            }).then(function(){
                return self.load_job_recruits(id, data);
            }, function(){
                return error();
            }).then(function(){
                return self.load_job_wanteds(id, data);
            }, function(){
                return error();
            }).then(function(){
                return self.load_trading_sells(id, data);
            }, function(){
                return error();
            }).then(function(){
                return self.load_trading_buys(id, data);
            }, function(){
                return error();
            }).then(function(){
                return self.load_exchange(data);
            }, function(){
                return error();
            }).then(function(){
                resolve(data);
            }, function(){
                reject();
            });

        });

        return promise;
    }


    load_house_rents(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let house = new T200House();
            house._table = "house_rent";
            house.city_id = id;
            house._fields = house.list_fields();
            return self.list(house.merge_multiple_list()).then(function(values){
                data.house_rents = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_house_wanted(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let house = new T200House();
            house._table = "house_wanted";
            house.city_id = id;
            house._fields = house.list_fields();
            return self.list(house.merge_multiple_list()).then(function(values){
                data.house_wanteds = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_job_recruits(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let job = new T200Job();
            job._table = "job_recruit";
            job.city_id = id;
            job._fields = job.list_fields();
            return self.list(job.merge_multiple_list()).then(function(values){
                data.job_recruits = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_job_wanteds(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let job = new T200Job();
            job._table = "job_wanted";
            job.city_id = id;
            job._fields = job.list_fields();
            return self.list(job.merge_multiple_list()).then(function(values){
                data.job_wanteds = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_trading_sells(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let trading = new T200Trading();
            trading._table = "trading_sell";
            trading.city_id = id;
            trading._fields = trading.list_fields();
            return self.list(trading.merge_multiple_list()).then(function(values){
                data.trading_sells = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_trading_buys(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let trading = new T200Trading();
            trading._table = "trading_buy";
            trading.city_id = id;
            trading._fields = trading.list_fields();
            return self.list(trading.merge_multiple_list()).then(function(values){
                data.trading_buys = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_exchange(data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let exchange = new T200Exchange();

            exchange._fields = exchange.list_fields();
            return self.list(exchange.merge_multiple_list()).then(function(values){
                data.exchanges = values;
                resolve(data);
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200HomeCityIndex;