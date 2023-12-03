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

        if(true){
            note._fields = note.admin_list_fields();
            note.paging_count_sql = note.merge_admin_paging_count();
            note.merge_paging = note.merge_admin_paging_list;
            AdminBiz.paging(note).then(function(result){
                let data = {};
                
                data.paging = result.paging;
                data.values = result.values;
                data.status = note.status;

                data.item_left = note.set_item_left();
                data.item_right = note.set_item_right();
                data.list_buttons = note.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/note/list";
                list_box._search_url = "/admin/note/search";
                list_box._change_status_url = "/admin/note/list";

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
            note.search = search;
            note._fields = note.admin_list_fields();
            note._search_fields = note.admin_fulltext_fields();
            note.fulltext_count_sql = note.merge_admin_fulltext_count();
            note.merge_fulltext = note.merge_admin_fulltext_list;
            AdminBiz.fulltext(note).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.status = note.status;

                data.item_left = note.set_item_left();
                data.item_right = note.set_item_right();
                data.list_buttons = note.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/note/list";
                list_box._search_url = "/admin/note/search";
                list_box._change_status_url = "/admin/note/list";
    
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


async function do_admin_note_approve(request, response, cookie, session, resource) {
    log(__filename, "do_admin_note_approve");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200AdminNote();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        note.user_id = session.get("userid");
        note.ids = request.get("ids");
        note.status = 1;

        if(T200HttpsForm.verify_id(note.user_id)
            && T200HttpsForm.verify_ids(note.ids)
            && T200HttpsForm.verify_id(note.status)){
            note._name_value = note.modify_status_array();
            AdminBiz.modify(note.merge_admin_status_update()).then(function(result){
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
            response.type("json");
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

        note.user_id = session.get("userid");
        note.ids = request.get("ids");
        note.status = -1;

        if(T200HttpsForm.verify_id(note.user_id)
            && T200HttpsForm.verify_ids(note.ids)
            && T200HttpsForm.verify_status(note.status)){
            note._name_value = note.modify_status_array();
            AdminBiz.modify(note.merge_admin_status_update()).then(function(result){
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
            response.type("json");
            reject(T200Error.build(1));
        }
    });

    return promise;
}


global.action.use_post('/admin/note/list', do_admin_note_list);
global.action.use_post('/admin/note/search', do_admin_note_search);
global.action.use_post('/admin/note/approve', do_admin_note_approve);
global.action.use_post('/admin/note/remove', do_admin_note_remove);