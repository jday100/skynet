const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200AdminNotice = require('../../../models/T200AdminNotice.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

async function do_admin_notice_edit(request, response, cookie, session, resource) {
    log(__filename, "do_admin_notice_edit");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


        let nid = cookie.get("nid");
        if(nid && 0 < nid){
            do_admin_notice_modify(request, response, cookie, session, resource, AdminBiz);
        }else{
            do_admin_notice_add(request, response, cookie, session, resource, AdminBiz).then(function(){
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

async function do_admin_notice_add(request, response, cookie, session, resource, AdminBiz) {
    log(__filename, "do_admin_notice_add");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200AdminNotice();
  
        notice.user_id = session.get("userid");
        notice.title = request.get("title");
        notice.content = request.get("content");
        
        if(T200HttpsForm.verify_id(notice.user_id)
            && T200HttpsForm.verify_text(notice.title)
            && T200HttpsForm.verify_text(notice.content)){
                notice.flash_admin_append_fields();
                notice.flash_admin_append_values();
                AdminBiz.append(notice.merge_admin_insert()).then(resolve, reject);
        }
    });

    return promise;
}

async function do_admin_notice_modify(request, response, cookie, session, resource, AdminBiz) {
    log(__filename, "do_admin_notice_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}


global.action.use_post('/admin/notice/edit', do_admin_notice_edit);

