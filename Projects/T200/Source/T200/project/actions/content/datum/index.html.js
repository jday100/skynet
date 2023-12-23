const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserDatum = require('../../../models/T200UserDatum.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_content_datum_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_datum_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let datum = new T200UserDatum();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        
        let status = request.get("status");

        switch(status){
            case '1':
                datum.status = request.get("status1");
                break;
            case '2':
                datum.status = request.get("status2");
                break;
            default:
                datum.status = status;
        }

        datum.user_id = session.get("userid");

        if(T200HttpsForm.verify_id(datum.user_id)){
            datum.flash_content_paging_fields();
            datum.merge_paging_count = datum.merge_user_paging_count;
            datum.merge_paging_list = datum.merge_user_paging_list;
            UserBiz.paging2(datum).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
                data.status = datum.status;
                data.item_left = datum.set_item_left();
                data.item_right = datum.set_item_right();
                data.list_buttons = datum.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/content/datum/list";
                list_box._search_url = "/content/datum/search";
                list_box._change_status_url = "/content/datum/list";

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

async function do_content_datum_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_note_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200UserNote();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        
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

        note.user_id = session.get("userid");

        if(T200HttpsForm.verify_id(note.user_id)
            //&& T200HttpsForm.verify_status(note.status)
            && T200HttpsForm.verify_text(search)){
                note._search = search;
                note.flash_content_paging_fields();
                note.flash_content_fulltext_fields();
                note.merge_fulltext_count = note.merge_user_fulltext_count;
                note.merge_fulltext_list = note.merge_user_fulltext_list;
                UserBiz.fulltext2(note).then(function(result){
                    let data = {};

                    data.paging = result.paging;
                    data.values = result.values;
                    data.search = note._search;
                    data.status = note.status;
                    data.item_left = note.set_item_left();
                    data.item_right = note.set_item_right();
                    data.list_buttons = note.set_list_buttons();
    
                    let list_box = new T200ListView(resource);
    
                    list_box._list_url = "/content/note/list";
                    list_box._search_url = "/content/note/search";
                    list_box._change_status_url = "/content/note/list";
    
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


async function do_content_datum_publish(request, response, cookie, session, resource) {
    log(__filename, "do_content_note_publish");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200UserNote();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        note.user_id = session.get("userid");
        note.ids = request.get("ids");
        note.status = 1;

        if(T200HttpsForm.verify_id(note.user_id)
            && T200HttpsForm.verify_ids(note.ids)
            && T200HttpsForm.verify_id(note.status)){
            note.flash_content_status_update();
            UserBiz.modify(note.merge_user_status_update()).then(function(){
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


async function do_content_datum_remove(request, response, cookie, session, resource) {
    log(__filename, "do_content_note_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200UserNote();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        note.user_id = session.get("userid");
        note.ids = request.get("ids");
        note.status = -1;

        if(T200HttpsForm.verify_id(note.user_id)
            && T200HttpsForm.verify_ids(note.ids)
            && T200HttpsForm.verify_status(note.status)){
            note.flash_content_status_update();
            UserBiz.modify(note.merge_user_status_update()).then(function(){
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


global.action.use_post('/content/datum/list', do_content_datum_list);
global.action.use_post('/content/datum/search', do_content_datum_search);
global.action.use_post('/content/datum/publish', do_content_datum_publish);
global.action.use_post('/content/datum/remove', do_content_datum_remove);