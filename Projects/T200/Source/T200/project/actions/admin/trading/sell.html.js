const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminTradingSell = require('../../../models/T200AdminTradingSell.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_trading_sell_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_trading_sell_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200AdminTradingSell();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


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

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){
            trading.flash_admin_paging_fields();
            trading.merge_paging_count = trading.merge_admin_paging_count;
            trading.merge_paging_list = trading.merge_admin_paging_list;
            AdminBiz.paging2(trading).then(function(result){
                let data = {};
                
                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
                data.status = trading.status;

                data.item_left = trading.set_item_left();
                data.item_right = trading.set_item_right();
                data.list_buttons = trading.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/trading/sell/list";
                list_box._search_url = "/admin/trading/sell/search";
                list_box._change_status_url = "/admin/trading/sell/list";

                return list_box.show(data).then(function(value){
                    response.type("json");
                    resolve(value);
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
            reject(T200Error.build(1));
        }
    
    });

    return promise;
}

async function do_admin_trading_sell_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_trading_sell_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200AdminTradingSell();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


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

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_text(search)){
            trading._search = search;
            trading.flash_admin_paging_fields();
            trading.flash_admin_fulltext_fields();
            trading.merge_fulltext_count = trading.merge_admin_fulltext_count;
            trading.merge_fulltext_list = trading.merge_admin_fulltext_list;
            AdminBiz.fulltext2(trading).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
                data.status = trading.status;

                data.item_left = trading.set_item_left();
                data.item_right = trading.set_item_right();
                data.list_buttons = trading.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/trading/sell/list";
                list_box._search_url = "/admin/trading/sell/search";
                list_box._change_status_url = "/admin/trading/sell/list";
    
                return list_box.show(data).then(function(value){
                    response.type("json");
                    resolve(value);
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
            reject(T200Error.build(1));
        }
    });

    return promise;
}


async function do_admin_trading_sell_approve(request, response, cookie, session, resource) {
    log(__filename, "do_admin_trading_sell_approve");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200AdminTradingSell();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");
        trading.ids = request.get("ids");
        trading.status = 1;

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_ids(trading.ids)
            && T200HttpsForm.verify_id(trading.status)){
            trading.flash_admin_status_update();
            AdminBiz.modify(trading.merge_admin_status_update()).then(function(){
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


async function do_admin_trading_sell_remove(request, response, cookie, session, resource) {
    log(__filename, "do_admin_trading_sell_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200AdminTradingSell();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");
        trading.ids = request.get("ids");
        trading.status = -1;

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_ids(trading.ids)
            && T200HttpsForm.verify_status(trading.status)){
            trading.flash_admin_status_update();
            AdminBiz.modify(trading.merge_admin_status_update()).then(function(){
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


global.action.use_post('/admin/trading/sell/list', do_admin_trading_sell_list);
global.action.use_post('/admin/trading/sell/search', do_admin_trading_sell_search);
global.action.use_post('/admin/trading/sell/approve', do_admin_trading_sell_approve);
global.action.use_post('/admin/trading/sell/remove', do_admin_trading_sell_remove);