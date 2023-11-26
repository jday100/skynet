const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserExchange = require('../../models/T200UserExchange.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_exchange_board(request, response, cookie, session, resource) {
    log(__filename, "do_exchange_board");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200UserExchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        exchange._fields = exchange.board_fields();
        exchange._order_direction = "DESC";
        UserBiz.board(exchange).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.exchanges = result.values;
            return view.render_file("exchange/exchange.ejs", data).then(function (value) {
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


global.action.use_post('/exchange/board', do_exchange_board);