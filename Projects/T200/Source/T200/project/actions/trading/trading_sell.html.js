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
        if(global.setup.server){
            if(global.setup.server.board){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }

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

async function do_trading_sell_reply(request, response, cookie, session, resource) {
    log(__filename, "do_trading_sell_reply");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        if(global.setup.server){
            if(global.setup.server.reply){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }

        let trading = new T200UserTradingSell();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let nickname = request.get("nickname");

        trading.user_id = session.get("userid");
        trading.identity_id = session.get("identityid");
        trading.city_id = session.get("cityid");
        trading.parent_id = request.get("parentid");
        trading.title = `@${nickname}`;
        trading.content = request.get("content");
        trading.status = 1;

        if(T200HttpsForm.verify_id(trading.user_id)
            && T200HttpsForm.verify_id(trading.identity_id)
            && T200HttpsForm.verify_id(trading.city_id)
            && T200HttpsForm.verify_id(trading.parent_id)
            && T200HttpsForm.verify_id(trading.status)
            && T200HttpsForm.verify_text(nickname)
            && T200HttpsForm.verify_text(trading.content)){
            trading.flash_reply_fields();
            trading.flash_reply_values();
            UserBiz.append(trading.merge_user_insert()).then(function(){
                do_trading_sell_board_panel(trading, UserBiz, cookie, resource).then(function(result){
                    response.type("json");
                    resolve(result);
                }, function(){
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


function do_trading_sell_board_panel(trading, UserBiz, cookie, resource) {
    log(__filename, "do_trading_sell_board_panel");
    let self = this;
    let promise = new Promise(function(resolve, reject){
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
                    resolve(value);
                }, function (err) {
                    reject();
                });
            }, function (err) {
                reject();
            });
        }else{
            reject();
        }
  
    });

    return promise;
}


global.action.use_post('/trading/sell/board', do_trading_sell_board);
global.action.use_post('/trading/sell/reply', do_trading_sell_reply);