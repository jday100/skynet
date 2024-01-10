const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200UserNote = require('../../../models/T200UserNote.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

async function do_content_note_edit(request, response, cookie, session, resource) {
    log(__filename, "do_content_note_edit");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let UserBiz = new T200HomeUserBiz(request, cookie, session);


        let nid = cookie.get("nid");
        if(nid && 0 < nid){
            do_content_note_modify(request, response, cookie, session, resource, UserBiz);
        }else{
            do_content_note_add(request, response, cookie, session, resource, UserBiz).then(function(){
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

async function do_content_note_add(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_note_add");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200UserNote();
  
        note.user_id = session.get("userid");
        note.status = session.get("status");
        note.title = request.get("title");
        note.content = request.get("content");
        
        if(T200HttpsForm.verify_id(note.user_id)
            && T200HttpsForm.verify_text(note.status)
            && T200HttpsForm.verify_text(note.title)
            && T200HttpsForm.verify_text(note.content)){
                note.flash_content_append_fields();
                note.flash_content_append_values();
                UserBiz.append(note.merge_user_insert()).then(resolve, reject);
        }
    });

    return promise;
}

async function do_content_note_modify(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_note_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}


global.action.use_post('/content/note/edit', do_content_note_edit);

