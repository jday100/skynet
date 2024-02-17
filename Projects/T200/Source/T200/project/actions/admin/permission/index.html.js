const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminGroup = require('../../../models/T200AdminGroup.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_permission_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_permission_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let group = new T200AdminGroup();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


        let status = request.get("status");

        switch(status){
            case '1':
                group.status = request.get("status1");
                break;
            case '2':
                group.status = request.get("status2");
                break;
            default:
                group.status = status;
        }

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){
            group.flash_admin_paging_fields();
            group.merge_paging_count = group.merge_admin_paging_count;
            group.merge_paging_list = group.merge_admin_paging_list;
            AdminBiz.paging2(group).then(function(result){
                let data = {};
                
                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
                data.status = group.status;

                data.item_left = group.set_item_left();
                data.item_right = group.set_item_right();
                data.list_buttons = group.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/group/list";
                list_box._search_url = "/admin/group/search";
                list_box._change_status_url = "/admin/group/list";

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

async function do_admin_permission_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_permission_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200AdminGroup();
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

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_text(search)){
            exchange._search = search;
            exchange.flash_admin_paging_fields();
            exchange.flash_admin_fulltext_fields();
            exchange.merge_fulltext_count = exchange.merge_admin_fulltext_count;
            exchange.merge_fulltext_list = exchange.merge_admin_fulltext_list;
            AdminBiz.fulltext2(exchange).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.search = exchange._search;
                data.status = exchange.status;

                data.item_left = exchange.set_item_left();
                data.item_right = exchange.set_item_right();
                data.list_buttons = exchange.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/exchange/list";
                list_box._search_url = "/admin/exchange/search";
                list_box._change_status_url = "/admin/exchange/list";
    
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


async function do_admin_permission_approve(request, response, cookie, session, resource) {
    log(__filename, "do_admin_permission_approve");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200AdminExchange();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");
        exchange.ids = request.get("ids");
        exchange.status = 1;

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_ids(exchange.ids)
            && T200HttpsForm.verify_id(exchange.status)){
            exchange.flash_admin_status_update();
            AdminBiz.modify(exchange.merge_admin_status_update()).then(function(){
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


async function do_admin_permission_remove(request, response, cookie, session, resource) {
    log(__filename, "do_admin_permission_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200AdminExchange();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");
        exchange.ids = request.get("ids");
        exchange.status = -1;

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_ids(exchange.ids)
            && T200HttpsForm.verify_status(exchange.status)){
            exchange.flash_admin_status_update();
            AdminBiz.modify(exchange.merge_admin_status_update()).then(function(){
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


global.action.use_post('/admin/permission/list', do_admin_permission_list);
global.action.use_post('/admin/permission/search', do_admin_permission_search);
global.action.use_post('/admin/permission/approve', do_admin_permission_approve);
global.action.use_post('/admin/permission/remove', do_admin_permission_remove);