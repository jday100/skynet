const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminInvitation = require('../../../models/T200AdminInvitation.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_invitation_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_invitation_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let invitation = new T200AdminInvitation();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


        let status = request.get("status");

        switch(status){
            case '1':
                invitation.status = request.get("status1");
                break;
            case '2':
                invitation.status = request.get("status2");
                break;
            default:
                invitation.status = status;
        }

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){
            invitation.flash_admin_paging_fields();
            invitation.merge_paging_count = invitation.merge_admin_paging_count;
            invitation.merge_paging_list = invitation.merge_admin_paging_list;
            AdminBiz.paging2(invitation).then(function(result){
                let data = {};
                
                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
                data.status = invitation.status;

                data.item_left = invitation.set_item_left();
                data.item_right = invitation.set_item_right();
                data.list_buttons = invitation.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/invitation/list";
                list_box._search_url = "/admin/invitation/search";
                list_box._change_status_url = "/admin/invitation/list";

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

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_text(search)){
            note._search = search;
            note.flash_admin_paging_fields();
            note.flash_admin_fulltext_fields();
            note.merge_fulltext_count = note.merge_admin_fulltext_count;
            note.merge_fulltext_list = note.merge_admin_fulltext_list;
            AdminBiz.fulltext2(note).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.search = note._search;
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

        let user_id = session.get("userid");
        note.ids = request.get("ids");
        note.status = 1;

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_ids(note.ids)
            && T200HttpsForm.verify_id(note.status)){
            note.flash_admin_status_update();
            AdminBiz.modify(note.merge_admin_status_update()).then(function(){
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


async function do_admin_note_remove(request, response, cookie, session, resource) {
    log(__filename, "do_admin_note_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200AdminNote();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");
        note.ids = request.get("ids");
        note.status = -1;

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_ids(note.ids)
            && T200HttpsForm.verify_status(note.status)){
            note.flash_admin_status_update();
            AdminBiz.modify(note.merge_admin_status_update()).then(function(){
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


global.action.use_post('/admin/invitation/list', do_admin_invitation_list);
global.action.use_post('/admin/invitation/search', do_admin_invitation_search);
global.action.use_post('/admin/invitation/approve', do_admin_invitation_approve);
global.action.use_post('/admin/invitation/remove', do_admin_invitation_remove);