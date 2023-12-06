const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserTradingSell = require('../../models/T200UserTradingSell.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_trading_sell_board(request, response, cookie, session, resource) {
    log(__filename, "do_trading_sell_board");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTradingSell();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let item = cookie.get("id");

        if(undefined == item){

        }else{
            trading.id = item._value;
        }

        if(T200HttpsForm.verify_id(trading.id)){
            trading.flash_user_board_fields();
            trading.merge_board_count = trading.merge_user_board_count;
            trading.merge_board_list = trading.merge_user_board_list;
            UserBiz.board(trading).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.tradings = result.values;
                return view.render_file("trading/trading_sell.ejs", data).then(function (value) {
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


global.action.use_post('/trading/sell/board', do_trading_sell_board);