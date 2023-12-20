const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeUserBiz = require('./T200HomeUserBiz.js');
const T200UserTradingSell = require('../models/T200UserTradingSell.js');
const T200UserTradingBuy = require('../models/T200UserTradingBuy.js');


class T200HomeTradingIndex extends T200HomeUserBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    load_index(id) {
        log(__filename, "load");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let data = {};

            self.load_trading_sell(id, data).then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.load_trading_buy(id, data);
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

    

    load_trading_sell(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let trading = new T200UserTradingSell();
            trading.region_id = id;
            trading._fields = trading.list_fields();
            return self.list(trading.merge_user_paging_region_list()).then(function(values){
                data.trading_sells = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_trading_buy(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let trading = new T200UserTradingBuy();
            trading.region_id = id;
            trading._fields = trading.list_fields();
            return self.list(trading.merge_user_paging_region_list()).then(function(values){
                data.trading_buys = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200HomeTradingIndex;