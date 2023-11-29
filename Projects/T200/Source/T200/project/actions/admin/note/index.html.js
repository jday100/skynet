const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminNote = require('../../../models/T200AdminNote.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_note_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_note_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200AdminNote();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let status = request.get("status");

        switch(status){
            case '1':
                note.status = request.get("status1");
                break;
            case '2':
                note.status = request.get("status2");
                break;
            default:
                note.status = status;
        }

        note._fields = note.list_status_fields();
        note._order_direction = "DESC";
        note.paging_count_sql = note.merge_status_count(note.status);
        note.merge_paging = note.merge_status_paging_test;
        AdminBiz.paging(note).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.values = result.values;
            data.status = note.status;
            let list = new T200ListView(resource);

            list._list_url = "/admin/note/list";
            list._search_url = "/admin/note/search";
            list._change_status_url = "/admin/note/list";

            data.item_left = note.set_item_left();
            data.item_right = note.set_item_right();
            data.list_buttons = note.set_list_buttons();

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

async function do_admin_note_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_note_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200AdminNote();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let status = request.get("status");
        let search = request.get("search");

        switch(status){
            case '1':
                note.status = request.get("status1");
                break;
            case '2':
                note.status = request.get("status2");
                break;
            default:
                note.status = status;
        }

        if(T200HttpsForm.verify_text(search)){
            note._search = search;
            note._fields = note.fulltext_result_fields();
            note._search_fields = note.fulltext_fields();
            note._order_direction = "DESC";
            note.fulltext_count_sql = note.merge_fulltext_count(note.status, search);
            //note.fulltext_list_sql = note.merge_fulltext_paging(note.status, search);
            note.merge_paging = note.merge_fulltext_test;
            AdminBiz.fulltext(note).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.values = result.values;
                data.status = note.status;

                let list = new T200ListView(resource);

                list._list_url = "/admin/note/list";
                list._search_url = "/admin/note/search";
                list._change_status_url = "/admin/note/list";

                data.item_left = note.set_item_left();
                data.item_right = note.set_item_right();
                data.list_buttons = note.set_list_buttons();
    
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



async function do_admin_note_approve(request, response, cookie, session, resource) {
    log(__filename, "do_admin_note_approve");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200AdminNote();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        note.ids = request.get("ids");
        note.status = 1;

        if(T200HttpsForm.verify_ids(note.ids)
            && T200HttpsForm.verify_id(note.status)){
            
            AdminBiz.modify(note.merge_status_update()).then(function(result){
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


async function do_admin_note_remove(request, response, cookie, session, resource) {
    log(__filename, "do_admin_note_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200AdminNote();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        note.ids = request.get("ids");
        note.status = -1;

        if(T200HttpsForm.verify_ids(note.ids)
            && T200HttpsForm.verify_status(note.status)){
            
            AdminBiz.modify(note.merge_status_update()).then(function(result){
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


global.action.use_post('/admin/note/list', do_admin_note_list);
global.action.use_post('/admin/note/search', do_admin_note_search);
global.action.use_post('/admin/note/approve', do_admin_note_approve);
global.action.use_post('/admin/note/remove', do_admin_note_remove);