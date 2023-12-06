const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserTradingBuy = require('../../../models/T200UserTradingBuy.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_content_trading_buy_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_trading_buy_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTradingBuy();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        
        let status = request.get("status");

        switch(status){
            case '1':
                trading.status = request.get("status1");
                break;
            case '2':
                trading.status = request.get("status2");
                break;
            default:
                trading.status = status;
        }

        trading.user_id = session.get("userid");

        if(T200HttpsForm.verify_id(trading.user_id)){
            trading.flash_content_paging_fields();
            trading.merge_paging_count = trading.merge_user_paging_count;
            trading.merge_paging_list = trading.merge_user_paging_list;
            UserBiz.paging2(trading).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
                data.status = trading.status;
                data.item_left = trading.set_item_left();
                data.item_right = trading.set_item_right();
                data.list_buttons = trading.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/content/trading/buy/list";
                list_box._search_url = "/content/trading/buy/search";
                list_box._change_status_url = "/content/trading/buy/list";

                return list_box.show(data).then(function(value){
                    response.type("json");
                    resolve(value);
                }, function(){
                    response.type("json");
                    reject();
                });
            }, function(){
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

async function do_content_trading_buy_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_trading_buy_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTradingBuy();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        
        let status = request.get("status");
        let search = request.get("search");

        switch(status){
            case '1':
                trading.status = request.get("status1");
                break;
            case '2':
                trading.status = request.get("status2");
                break;
            default:
                trading.status = status;
        }

        trading.user_id = session.get("userid");

        if(T200HttpsForm.verify_id(trading.user_id)
            //&& T200HttpsForm.verify_status(trading.status)
            && T200HttpsForm.verify_text(search)){
                trading._search = search;
                trading.flash_content_paging_fields();
                trading.flash_content_fulltext_fields();
                trading.merge_fulltext_count = trading.merge_user_fulltext_count;
                trading.merge_fulltext_list = trading.merge_user_fulltext_list;
                UserBiz.fulltext2(trading).then(function(result){
                    let data = {};

                    data.paging = result.paging;
                    data.values = result.values;
                    data.search = trading._search;
                    data.status = trading.status;
                    data.item_left = trading.set_item_left();
                    data.item_right = trading.set_item_right();
                    data.list_buttons = trading.set_list_buttons();
    
                    let list_box = new T200ListView(resource);
    
                    list_box._list_url = "/content/trading/buy/list";
                    list_box._search_url = "/content/trading/buy/search";
                    list_box._change_status_url = "/content/trading/buy/list";
    
                    return list_box.show(data).then(function(value){
                        response.type("json");
                        resolve(value);
                    }, function(){
                        response.type("json");
                        reject();
                    });
                }, function(){
                    response.type("json");
                    reject();
                });
        }else{
            response.type("json");
            reject(T200Error.build(1));
        }

    });

    return promise;
}


async function do_content_trading_buy_publish(request, response, cookie, session, resource) {
    log(__filename, "do_content_trading_buy_publish");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTradingBuy();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        trading.user_id = session.get("userid");
        trading.ids = request.get("ids");
        trading.status = 1;

        if(T200HttpsForm.verify_id(trading.user_id)
            && T200HttpsForm.verify_ids(trading.ids)
            && T200HttpsForm.verify_id(trading.status)){
            trading.flash_content_status_update();
            UserBiz.modify(trading.merge_user_status_update()).then(function(){
                response.type("json");
                resolve();
            }, function (err) {
                response.type("json");
                reject();
            });

        }else{
            response.type("json");
            reject(T200Error.build(1));
        }
    });

    return promise;
}


async function do_content_trading_buy_remove(request, response, cookie, session, resource) {
    log(__filename, "do_content_trading_buy_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200UserTradingBuy();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        trading.user_id = session.get("userid");
        trading.ids = request.get("ids");
        trading.status = -1;

        if(T200HttpsForm.verify_id(trading.user_id)
            && T200HttpsForm.verify_ids(trading.ids)
            && T200HttpsForm.verify_status(trading.status)){
            trading.flash_content_status_update();
            UserBiz.modify(trading.merge_user_status_update()).then(function(){
                response.type("json");
                resolve();
            }, function (err) {
                response.type("json");
                reject();
            });

        }else{
            response.type("json");
            reject(T200Error.build(1));
        }
    });

    return promise;
}


global.action.use_post('/content/trading/buy/list', do_content_trading_buy_list);
global.action.use_post('/content/trading/buy/search', do_content_trading_buy_search);
global.action.use_post('/content/trading/buy/publish', do_content_trading_buy_publish);
global.action.use_post('/content/trading/buy/remove', do_content_trading_buy_remove);