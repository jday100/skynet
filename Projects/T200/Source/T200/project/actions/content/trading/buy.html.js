const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200Trading = require('../../../models/T200Trading.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');


async function do_content_trading_buy_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_trading_buy_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200Trading();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        trading._table = "trading_buy";
        trading._fields = trading.list_fields();
        trading._order_direction = "DESC";
        trading.paging_count_sql = trading.merge_count();
        trading.paging_list_sql = trading.merge_paging();
        UserBiz.paging(trading).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.tradings = result.values;
            return view.render_file("content/trading/buy_index.ejs", data).then(function (value) {
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
    
    });

    return promise;
}

async function do_content_trading_buy_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_trading_buy_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200Trading();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        trading._table = "trading_buy";
        trading._fields = trading.fulltext_result_fields();
        trading._search_fields = trading.fulltext_fields();
        trading._order_direction = "DESC";
        UserBiz.fulltext(trading).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.tradings = result.values;
            return view.render_file("content/trading/buy_index.ejs", data).then(function (value) {
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

    });

    return promise;
}


global.action.use_post('/content/trading/buy/list', do_content_trading_buy_list);
global.action.use_post('/content/trading/buy/search', do_content_trading_buy_search);