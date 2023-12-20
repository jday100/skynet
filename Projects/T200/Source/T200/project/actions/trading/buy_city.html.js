const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserTradingBuy = require('../../models/T200UserTradingBuy.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_trading_buy_city_list(request, response, cookie, session, resource) {
    log(__filename, "do_trading_buy_city_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTradingBuy();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let city_id = request.get("id");

        if(T200HttpsForm.verify_id(city_id)){
            trading.city_id = city_id;
            trading._fields = trading.list_fields();
            trading.merge_paging_count = trading.merge_user_paging_city_count;
            trading.merge_paging_list = trading.merge_user_paging_city_list;
            UserBiz.paging2(trading).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.city_id = city_id;
                data.paging = result.paging;
                data.tradings = result.values;
                return view.render_file("trading/buy_city.ejs", data).then(function (value) {
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


global.action.use_post('/trading/buy/city/list', do_trading_buy_city_list);