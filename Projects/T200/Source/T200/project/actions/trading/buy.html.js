const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserTradingBuy = require('../../models/T200UserTradingBuy.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_trading_buy_list(request, response, cookie, session, resource) {
    log(__filename, "do_trading_buy_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTradingBuy();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        if(true){
            trading._fields = trading.list_fields();
            trading.merge_paging_count = trading.merge_user_paging_home_count;
            trading.merge_paging_list = trading.merge_user_paging_home_list;
            UserBiz.paging2(trading).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.tradings = result.values;
                return view.render_file("trading/buy.ejs", data).then(function (value) {
                    response.type("json");
                    resolve(value);
                }, function (err) {
                    response.type("json");
                    reject();
                });
            }, function (err) {
                response.type("json");
                reject();
            });
        }else{
            response.type("json");
            reject();
        }
  
    });

    return promise;
}


async function do_trading_buy_search(request, response, cookie, session, resource) {
    log(__filename, "do_trading_buy_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTradingBuy();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let search = request.get("search");

        if(T200HttpsForm.verify_text(search)){
            trading._search = search;
            trading.flash_paging_fields();
            trading.flash_fulltext_fields();
            trading.merge_fulltext_count = trading.merge_home_fulltext_count;
            trading.merge_fulltext_list = trading.merge_home_fulltext_list;
            UserBiz.fulltext2(trading).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.tradings = result.values;
                data.search = trading._search;
                return view.render_file("trading/buy.ejs", data).then(function (value) {
                    response.type("json");
                    resolve(value);
                }, function (err) {
                    response.type("json");
                    reject();
                });
            }, function (err) {
                response.type("json");
                reject();
            });
        }else{
            response.type("json");
            reject();
        }
  
    });

    return promise;
}


global.action.use_post('/trading/buy/list', do_trading_buy_list);
global.action.use_post('/trading/buy/search', do_trading_buy_search);