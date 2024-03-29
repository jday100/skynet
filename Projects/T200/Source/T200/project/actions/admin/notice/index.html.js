const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminNotice = require('../../../models/T200AdminNotice.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_notice_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_notice_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200AdminNotice();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let status = request.get("status");

        switch(status){
            case '1':
                notice.status = request.get("status1");
                break;
            case '2':
                notice.status = request.get("status2");
                break;
            default:
                notice.status = status;
        }

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){
            notice.flash_admin_paging_fields();
            notice.merge_paging_count = notice.merge_admin_paging_count;
            notice.merge_paging_list = notice.merge_admin_paging_list;
            AdminBiz.paging2(notice).then(function(result){
                let data = {};
                
                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
                data.status = notice.status;

                data.item_left = notice.set_item_left();
                data.item_right = notice.set_item_right();
                data.list_buttons = notice.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/notice/list";
                list_box._search_url = "/admin/notice/search";
                list_box._change_status_url = "/admin/notice/list";

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

async function do_admin_notice_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_notice_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200AdminNotice();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


        let status = request.get("status");
        let search = request.get("search");

        switch(status){
            case '1':
                notice.status = request.get("status1");
                break;
            case '2':
                notice.status = request.get("status2");
                break;
            default:
                notice.status = status;
        }

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_text(search)){
            notice._search = search;
            notice.flash_admin_paging_fields();
            notice.flash_admin_fulltext_fields();
            notice.merge_fulltext_count = notice.merge_admin_fulltext_count;
            notice.merge_fulltext_list = notice.merge_admin_fulltext_list;
            AdminBiz.fulltext2(notice).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.search = notice._search;
                data.status = notice.status;

                data.item_left = notice.set_item_left();
                data.item_right = notice.set_item_right();
                data.list_buttons = notice.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/notice/list";
                list_box._search_url = "/admin/notice/search";
                list_box._change_status_url = "/admin/notice/list";
    
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


async function do_admin_notice_approve(request, response, cookie, session, resource) {
    log(__filename, "do_admin_notice_approve");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200AdminNotice();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");
        notice.ids = request.get("ids");
        notice.status = 1;

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_ids(notice.ids)
            && T200HttpsForm.verify_id(notice.status)){
            notice.flash_admin_status_update();
            AdminBiz.modify(notice.merge_admin_status_update()).then(function(){
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


async function do_admin_notice_remove(request, response, cookie, session, resource) {
    log(__filename, "do_admin_notice_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200AdminNotice();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");
        notice.ids = request.get("ids");
        notice.status = -1;

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_ids(notice.ids)
            && T200HttpsForm.verify_status(notice.status)){
            notice.flash_admin_status_update();
            AdminBiz.modify(notice.merge_admin_status_update()).then(function(){
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


global.action.use_post('/admin/notice/list', do_admin_notice_list);
global.action.use_post('/admin/notice/search', do_admin_notice_search);
global.action.use_post('/admin/notice/approve', do_admin_notice_approve);
global.action.use_post('/admin/notice/remove', do_admin_notice_remove);