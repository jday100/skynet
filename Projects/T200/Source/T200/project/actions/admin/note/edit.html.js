const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200Note = require('../../../models/T200Note.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

async function do_admin_note_edit(request, response, cookie, session, resource) {
    log(__filename, "do_admin_note_edit");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


        let nid = cookie.get("nid");
        if(nid && 0 < nid){
            do_admin_note_modify(request, response, cookie, session, resource, AdminBiz);
        }else{
            do_admin_note_add(request, response, cookie, session, resource, AdminBiz).then(function(){
                response.type("json");
                resolve();
            }, function(err){
                response.type("json");
                reject();
            });
        }
  
    });

    return promise;
}

async function do_admin_note_add(request, response, cookie, session, resource, AdminBiz) {
    log(__filename, "do_admin_note_add");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200Note();
  
        note.user_id = session.get("userid");
        note.title = request.get("title");
        note.content = request.get("content");
        
        if(T200HttpsForm.verify_id(note.user_id)
            && T200HttpsForm.verify_text(note.title)
            && T200HttpsForm.verify_text(note.content)){
                note._values = note.values();
                AdminBiz.add(note).then(resolve, reject);
        }
    });

    return promise;
}

async function do_admin_note_modify(request, response, cookie, session, resource, AdminBiz) {
    log(__filename, "do_admin_note_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}


global.action.use_post('/admin/note/edit', do_admin_note_edit);

