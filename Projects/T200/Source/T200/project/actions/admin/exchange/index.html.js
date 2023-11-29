const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminExchange = require('../../../models/T200AdminExchange.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_exchange_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_exchange_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200AdminExchange();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


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

        exchange._fields = exchange.list_status_fields();
        exchange._order_direction = "DESC";
        exchange.paging_count_sql = exchange.merge_status_count(exchange.status);
        exchange.merge_paging = exchange.merge_status_paging_test;
        AdminBiz.paging(exchange).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.values = result.values;
            data.status = exchange.status;
            let list = new T200ListView(resource);

            list._list_url = "/admin/exchange/list";
            list._search_url = "/admin/exchange/search";
            list._change_status_url = "/admin/exchange/list";

            data.item_left = exchange.set_item_left();
            data.item_right = exchange.set_item_right();
            data.list_buttons = exchange.set_list_buttons();

            return list.show(data).then(function(value){
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
    
    });

    return promise;
}

async function do_admin_exchange_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_exchange_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200AdminExchange();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

 
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

        if(T200HttpsForm.verify_text(search)){
            exchange._search = search;
            exchange._fields = exchange.fulltext_result_fields();
            exchange._search_fields = exchange.fulltext_fields();
            exchange._order_direction = "DESC";
            exchange.fulltext_count_sql = exchange.merge_fulltext_count(exchange.status, search);
   
            exchange.merge_paging = exchange.merge_fulltext_test;
            AdminBiz.fulltext(exchange).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.values = result.values;
                data.status = exchange.status;

                let list = new T200ListView(resource);

                list._list_url = "/admin/exchange/list";
                list._search_url = "/admin/exchange/search";
                list._change_status_url = "/admin/exchange/list";

                data.item_left = exchange.set_item_left();
                data.item_right = exchange.set_item_right();
                data.list_buttons = exchange.set_list_buttons();
    
                return list.show(data).then(function(value){
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
            reject(T200Error.build(1));
        }

    });

    return promise;
}


async function do_admin_exchange_approve(request, response, cookie, session, resource) {
    log(__filename, "do_admin_exchange_approve");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200AdminExchange();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        exchange.ids = request.get("ids");
        exchange.status = 1;

        if(T200HttpsForm.verify_ids(exchange.ids)
            && T200HttpsForm.verify_id(exchange.status)){
            
            AdminBiz.modify(exchange.merge_status_update()).then(function(result){
                if(result){
                    response.type("json");
                    resolve();
                }else{
                    response.type("json");
                    reject();
                }
            }, function (err) {
                response.type("json");
                reject();
            });

        }else{
            reject(T200Error.build(1));
        }
    });

    return promise;
}


async function do_admin_exchange_remove(request, response, cookie, session, resource) {
    log(__filename, "do_admin_exchange_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200AdminExchange();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        exchange.ids = request.get("ids");
        exchange.status = -1;

        if(T200HttpsForm.verify_ids(exchange.ids)
            && T200HttpsForm.verify_status(exchange.status)){
            
            AdminBiz.modify(exchange.merge_status_update()).then(function(result){
                if(result){
                    response.type("json");
                    resolve();
                }else{
                    response.type("json");
                    reject();
                }
            }, function (err) {
                response.type("json");
                reject();
            });

        }else{
            reject(T200Error.build(1));
        }
    });

    return promise;
}



global.action.use_post('/admin/exchange/list', do_admin_exchange_list);
global.action.use_post('/admin/exchange/search', do_admin_exchange_search);
global.action.use_post('/admin/exchange/approve', do_admin_exchange_approve);
global.action.use_post('/admin/exchange/remove', do_admin_exchange_remove);