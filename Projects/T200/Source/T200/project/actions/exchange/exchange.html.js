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
        if(global.setup.server){
            if(global.setup.server.board){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }

        let exchange = new T200UserExchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let item = cookie.get("id");

        if(undefined == item){

        }else{
            exchange.id = item._value;
        }

        if(T200HttpsForm.verify_id(exchange.id)){
            exchange.flash_user_board_fields();
            exchange.merge_board_count = exchange.merge_user_board_count;
            exchange.merge_board_list = exchange.merge_user_board_list;
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
        }else{
            response.type("json");
            reject();
        }
  
    });

    return promise;
}

async function do_exchange_reply(request, response, cookie, session, resource) {
    log(__filename, "do_exchange_reply");
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

        let exchange = new T200UserExchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let nickname = request.get("nickname");

        exchange.user_id = session.get("userid");
        exchange.identity_id = session.get("identityid");
        exchange.city_id = session.get("cityid");
        exchange.parent_id = request.get("parentid");
        exchange.parent_nickname = request.get("parentnickname");
        exchange.title = `@${nickname}`;
        exchange.content = request.get("content");
        exchange.status = 1;

        if(T200HttpsForm.verify_id(exchange.user_id)
            && T200HttpsForm.verify_id(exchange.identity_id)
            && T200HttpsForm.verify_id(exchange.city_id)
            && T200HttpsForm.verify_id(exchange.parent_id)
            && T200HttpsForm.verify_id(exchange.status)
            && T200HttpsForm.verify_text(nickname)
            && T200HttpsForm.verify_text(exchange.parent_nickname)
            && T200HttpsForm.verify_text(exchange.content)){
            exchange.flash_reply_fields();
            exchange.flash_reply_values();
            UserBiz.append(exchange.merge_user_insert()).then(function(){
                do_exchange_board_panel(exchange, UserBiz, cookie, resource).then(function(result){
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


function do_exchange_board_panel(exchange, UserBiz, cookie, resource) {
    log(__filename, "do_exchange_board_panel");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let item = cookie.get("id");

        if(undefined == item){

        }else{
            exchange.id = item._value;
        }

        if(T200HttpsForm.verify_id(exchange.id)){
            exchange.flash_user_board_fields();
            exchange.merge_board_count = exchange.merge_user_board_count;
            exchange.merge_board_list = exchange.merge_user_board_list;
            UserBiz.board(exchange).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.exchanges = result.values;
                return view.render_file("exchange/exchange.ejs", data).then(function (value) {
                    
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


global.action.use_post('/exchange/board', do_exchange_board);
global.action.use_post('/exchange/reply', do_exchange_reply);