const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserExchange = require('../../../models/T200UserExchange.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_content_exchange_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200UserExchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        
        let status = request.get("status");

        switch(status){
            case '1':
                exchange.status = request.get("status1");
                break;
            case '2':
                exchange.status = request.get("status2");
                break;
            default:
                exchange.status = status;
        }

        exchange.user_id = session.get("userid");

        if(T200HttpsForm.verify_id(exchange.user_id)){
            exchange.flash_content_paging_fields();
            exchange.merge_paging_count = exchange.merge_user_paging_count;
            exchange.merge_paging_list = exchange.merge_user_paging_list;
            UserBiz.paging2(exchange).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
                data.status = exchange.status;
                data.item_left = exchange.set_item_left();
                data.item_right = exchange.set_item_right();
                data.list_buttons = exchange.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/content/exchange/list";
                list_box._search_url = "/content/exchange/search";
                list_box._change_status_url = "/content/exchange/list";

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

async function do_content_exchange_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200UserExchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        
        let status = request.get("status");
        let search = request.get("search");

        switch(status){
            case '1':
                exchange.status = request.get("status1");
                break;
            case '2':
                exchange.status = request.get("status2");
                break;
            default:
                exchange.status = status;
        }

        exchange.user_id = session.get("userid");

        if(T200HttpsForm.verify_id(exchange.user_id)
            //&& T200HttpsForm.verify_status(exchange.status)
            && T200HttpsForm.verify_text(search)){
                exchange._search = search;
                exchange.flash_content_paging_fields();
                exchange.flash_content_fulltext_fields();
                exchange.merge_fulltext_count = exchange.merge_user_fulltext_count;
                exchange.merge_fulltext_list = exchange.merge_user_fulltext_list;
                UserBiz.fulltext2(exchange).then(function(result){
                    let data = {};

                    data.paging = result.paging;
                    data.values = result.values;
                    data.search = exchange._search;
                    data.status = exchange.status;
                    data.item_left = exchange.set_item_left();
                    data.item_right = exchange.set_item_right();
                    data.list_buttons = exchange.set_list_buttons();
    
                    let list_box = new T200ListView(resource);
    
                    list_box._list_url = "/content/exchange/list";
                    list_box._search_url = "/content/exchange/search";
                    list_box._change_status_url = "/content/exchange/list";
    
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


async function do_content_exchange_publish(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_publish");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200UserExchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        exchange.user_id = session.get("userid");
        exchange.identity_id = session.get("identityid");
        exchange.ids = request.get("ids");
        exchange.status = 1;

        if(T200HttpsForm.verify_id(exchange.user_id)
            && T200HttpsForm.verify_id(exchange.identity_id)
            && T200HttpsForm.verify_ids(exchange.ids)
            && T200HttpsForm.verify_id(exchange.status)){
            exchange.flash_content_status_update();
            UserBiz.modify(exchange.merge_user_status_update()).then(function(){
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


async function do_content_exchange_remove(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200UserExchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        exchange.user_id = session.get("userid");
        exchange.identity_id = session.get("identityid");
        exchange.ids = request.get("ids");
        exchange.status = -1;

        if(T200HttpsForm.verify_id(exchange.user_id)
            && T200HttpsForm.verify_id(exchange.identity_id)
            && T200HttpsForm.verify_ids(exchange.ids)
            && T200HttpsForm.verify_status(exchange.status)){
            exchange.flash_content_status_update();
            UserBiz.modify(exchange.merge_user_status_update()).then(function(){
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


global.action.use_post('/content/exchange/list', do_content_exchange_list);
global.action.use_post('/content/exchange/search', do_content_exchange_search);
global.action.use_post('/content/exchange/publish', do_content_exchange_publish);
global.action.use_post('/content/exchange/remove', do_content_exchange_remove);