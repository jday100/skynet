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
            trading.paging_count_sql = trading.merge_user_paging_type_count();
            trading.merge_paging = trading.merge_user_paging_type_list;
            UserBiz.paging(trading).then(function(result){
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


global.action.use_post('/trading/buy/list', do_trading_buy_list);