const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200UserJobRecruit = require('../../../models/T200UserJobRecruit.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

async function do_content_job_recruit_edit(request, response, cookie, session, resource) {
    log(__filename, "do_content_job_recruit_edit");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        if(global.setup.server){
            if(global.setup.server.publish){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }
        
        let UserBiz = new T200HomeUserBiz(request, cookie, session);


        let rid = cookie.get("rid");
        if(rid && 0 < rid){
            do_content_job_recruit_modify(request, response, cookie, session, resource, UserBiz);
        }else{
            do_content_job_recruit_add(request, response, cookie, session, resource, UserBiz).then(function(){
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

async function do_content_job_recruit_add(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_job_recruit_add");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200UserJobRecruit();
  
        job.user_id = session.get("userid");
        job.identity_id = session.get("identityid");
        job.status = session.get("status");
        job.continent_id = session.get("continentid");
        job.continent_name = session.get("continent");
        job.region_id = session.get("regionid");
        job.region_name = session.get("region");
        job.city_id = session.get("cityid");
        job.city_name = session.get("city");
        job.title = request.get("title");
        job.content = request.get("content");

        let type = request.get("type");

        if(1 == type){
            job.type_full = 1;
            job.type_part = 0;
        }else if(2 == type){
            job.type_full = 0;
            job.type_part = 1;
        }else if(0 == type){
            job.type_full = 1;
            job.type_part = 1;
        }
        
        if(T200HttpsForm.verify_id(job.user_id)
            && T200HttpsForm.verify_id(job.identity_id)
            && T200HttpsForm.verify_id(job.status)
            && T200HttpsForm.verify_id(job.continent_id)
            && T200HttpsForm.verify_text(job.continent_name)
            && T200HttpsForm.verify_id(job.region_id)
            && T200HttpsForm.verify_text(job.region_name)
            && T200HttpsForm.verify_id(job.city_id)
            && T200HttpsForm.verify_text(job.city_name)
            && T200HttpsForm.verify_text(job.title)
            && T200HttpsForm.verify_text(job.content)){
                job.flash_content_append_fields();
                job.flash_content_append_values();
                UserBiz.append(job.merge_user_insert()).then(function(id){
                    job.parent_id = id;
                    job.id = id;
                    if(T200HttpsForm.verify_id(job.parent_id)){
                        job.flash_content_parent_update();
                        UserBiz.modify(job.merge_update_by_key()).then(function(){
                            response.type("json");
                            resolve();
                        }, function(){
                            response.type("json");
                            reject();
                        });
                    }
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

async function do_content_job_recruit_modify(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_job_recruit_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}


global.action.use_post('/content/job/recruit/edit', do_content_job_recruit_edit);

