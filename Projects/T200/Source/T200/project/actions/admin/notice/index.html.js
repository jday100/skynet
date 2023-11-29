const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminNotice = require('../../../models/T200AdminNotice.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


function build_view(resource) {
    var list = new T200ListView(resource);

    list._list_url = "/admin/notice/list";
    list._search_url = "/admin/notice/search";
    list._change_status_url = "/admin/notice/list";

    return list;
}


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

        if(true){
            notice._fields = notice.list_status_fields();
            notice._order_direction = "DESC";
            notice.paging_count_sql = notice.merge_status_count(notice.status);
            //notice.paging_list_sql = notice.merge_paging();
            notice.merge_paging = notice.merge_status_paging_test;
            AdminBiz.paging(notice).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.values = result.values;
                data.status = notice.status;

                data.item_left = notice.set_item_left();
                data.item_right = notice.set_item_right();
                data.list_buttons = notice.set_list_buttons();

                let list = build_view(resource);                

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

        if(T200HttpsForm.verify_text(search)){
            notice._search = search;
            notice._fields = notice.fulltext_result_fields();
            notice._search_fields = notice.fulltext_fields();
            notice._order_direction = "DESC";
            notice.fulltext_count_sql = notice.merge_fulltext_count(notice.status, search);

            notice.merge_paging = notice.merge_fulltext_test;
            AdminBiz.fulltext(notice).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.values = result.values;
                data.status = notice.status;

                data.item_left = notice.set_item_left();
                data.item_right = notice.set_item_right();
                data.list_buttons = notice.set_list_buttons();

                let list = build_view(resource);   
    
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


async function do_admin_notice_approve(request, response, cookie, session, resource) {
    log(__filename, "do_admin_notice_approve");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200AdminNotice();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        notice.ids = request.get("ids");
        notice.status = 1;

        if(T200HttpsForm.verify_ids(notice.ids)
            && T200HttpsForm.verify_id(notice.status)){
            
            AdminBiz.modify(notice.merge_status_update()).then(function(result){
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


async function do_admin_notice_remove(request, response, cookie, session, resource) {
    log(__filename, "do_admin_notice_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200AdminNotice();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        notice.ids = request.get("ids");
        notice.status = -1;

        if(T200HttpsForm.verify_ids(notice.ids)
            && T200HttpsForm.verify_status(notice.status)){
            
            AdminBiz.modify(notice.merge_status_update()).then(function(result){
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


global.action.use_post('/admin/notice/list', do_admin_notice_list);
global.action.use_post('/admin/notice/search', do_admin_notice_search);
global.action.use_post('/admin/notice/approve', do_admin_notice_approve);
global.action.use_post('/admin/notice/remove', do_admin_notice_remove);