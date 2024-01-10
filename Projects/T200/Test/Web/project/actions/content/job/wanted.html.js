const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserJobWanted = require('../../../models/T200UserJobWanted.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_content_job_wanted_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_job_wanted_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200UserJobWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        
        let status = request.get("status");

        switch(status){
            case '1':
                job.status = request.get("status1");
                break;
            case '2':
                job.status = request.get("status2");
                break;
            default:
                job.status = status;
        }

        job.user_id = session.get("userid");
        job.identity_id = session.get("identityid");

        if(T200HttpsForm.verify_id(job.user_id)
            && T200HttpsForm.verify_id(job.identity_id)){
            job.flash_content_paging_fields();
            job.merge_paging_count = job.merge_user_paging_count;
            job.merge_paging_list = job.merge_user_paging_list;
            UserBiz.paging2(job).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
                data.status = job.status;
                data.item_left = job.set_item_left();
                data.item_right = job.set_item_right();
                data.list_buttons = job.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/content/job/wanted/list";
                list_box._search_url = "/content/job/wanted/search";
                list_box._change_status_url = "/content/job/wanted/list";

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

async function do_content_job_wanted_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_job_wanted_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200UserJobWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        
        let status = request.get("status");
        let search = request.get("search");

        switch(status){
            case '1':
                job.status = request.get("status1");
                break;
            case '2':
                job.status = request.get("status2");
                break;
            default:
                job.status = status;
        }

        job.user_id = session.get("userid");
        job.identity_id = session.get("identityid");

        if(T200HttpsForm.verify_id(job.user_id)
            && T200HttpsForm.verify_id(job.identity_id)
            && T200HttpsForm.verify_text(search)){
                job._search = search;
                job.flash_content_paging_fields();
                job.flash_content_fulltext_fields();
                job.merge_fulltext_count = job.merge_user_fulltext_count;
                job.merge_fulltext_list = job.merge_user_fulltext_list;
                UserBiz.fulltext2(job).then(function(result){
                    let data = {};

                    data.paging = result.paging;
                    data.values = result.values;
                    data.search = job._search;
                    data.status = job.status;
                    data.item_left = job.set_item_left();
                    data.item_right = job.set_item_right();
                    data.list_buttons = job.set_list_buttons();
    
                    let list_box = new T200ListView(resource);
    
                    list_box._list_url = "/content/job/wanted/list";
                    list_box._search_url = "/content/job/wanted/search";
                    list_box._change_status_url = "/content/job/wanted/list";
    
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


async function do_content_job_wanted_publish(request, response, cookie, session, resource) {
    log(__filename, "do_content_job_wanted_publish");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200UserJobWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        job.user_id = session.get("userid");
        job.identity_id = session.get("identityid");
        job.ids = request.get("ids");
        job.status = 1;

        if(T200HttpsForm.verify_id(job.user_id)
            && T200HttpsForm.verify_id(job.identity_id)
            && T200HttpsForm.verify_ids(job.ids)
            && T200HttpsForm.verify_id(job.status)){
            job.flash_content_status_update();
            UserBiz.modify(job.merge_user_status_update()).then(function(){
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


async function do_content_job_wanted_remove(request, response, cookie, session, resource) {
    log(__filename, "do_content_job_wanted_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200UserJobWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        job.user_id = session.get("userid");
        job.identity_id = session.get("identityid");
        job.ids = request.get("ids");
        job.status = -1;

        if(T200HttpsForm.verify_id(job.user_id)
            && T200HttpsForm.verify_id(job.identity_id)
            && T200HttpsForm.verify_ids(job.ids)
            && T200HttpsForm.verify_status(job.status)){
            job.flash_content_status_update();
            UserBiz.modify(job.merge_user_status_update()).then(function(){
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


global.action.use_post('/content/job/wanted/list', do_content_job_wanted_list);
global.action.use_post('/content/job/wanted/search', do_content_job_wanted_search);
global.action.use_post('/content/job/wanted/publish', do_content_job_wanted_publish);
global.action.use_post('/content/job/wanted/remove', do_content_job_wanted_remove);