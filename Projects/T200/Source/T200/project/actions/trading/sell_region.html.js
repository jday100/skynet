const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserTradingSell = require('../../models/T200UserTradingSell.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_trading_sell_region_list(request, response, cookie, session, resource) {
    log(__filename, "do_trading_sell_region_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTradingSell();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let region_id = request.get("id");

        if(T200HttpsForm.verify_id(region_id)){
            trading.region_id = region_id;
            trading._fields = trading.list_fields();
            trading.merge_paging_count = trading.merge_user_paging_region_count;
            trading.merge_paging_list = trading.merge_user_paging_region_list;
            UserBiz.paging2(trading).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.region_id = region_id;
                data.paging = result.paging;
                data.tradings = result.values;
                return view.render_file("trading/sell_region.ejs", data).then(function (value) {
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


async function do_trading_sell_region_search(request, response, cookie, session, resource) {
    log(__filename, "do_trading_sell_region_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTradingSell();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let region_id = request.get("id");
        let search = request.get("search");

        if(T200HttpsForm.verify_id(region_id)
            && T200HttpsForm.verify_text(search)){
            trading.region_id = region_id;
            trading._search = search;
            trading.flash_paging_fields();
            trading.flash_fulltext_fields();
            trading.merge_fulltext_count = trading.merge_user_fulltext_region_count;
            trading.merge_fulltext_list = trading.merge_user_fulltext_region_list;
            UserBiz.fulltext2(trading).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.region_id = region_id;
                data.paging = result.paging;
                data.tradings = result.values;
                data.search = trading._search;
                return view.render_file("trading/sell_region.ejs", data).then(function (value) {
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


global.action.use_post('/trading/sell/region/list', do_trading_sell_region_list);
global.action.use_post('/trading/sell/region/search', do_trading_sell_region_search);