const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserTrading = require('../../models/T200UserTrading.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_trading_sell_list(request, response, cookie, session, resource) {
    log(__filename, "do_trading_sell_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTrading();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let item = cookie.get("id");

        if(undefined == item){

        }else{
            trading.id = item._value;
        }

        if(T200HttpsForm.verify_id(trading.id)){
            trading._table = "trading_sell";
            trading._fields = trading.board_fields();
            trading._order_direction = "DESC";
            trading.board_count_sql = trading.merge_board_count(trading.id);
            trading.board_list_sql = trading.merge_board_list(trading.id);
            UserBiz.board(trading).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.tradings = result.values;
                return view.render_file("trading/sell.ejs", data).then(function (value) {
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
            reject();
        }

    });

    return promise;
}


global.action.use_post('/trading/sell/list', do_trading_sell_list);