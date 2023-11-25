const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200Job = require('../../../models/T200Job.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

async function do_content_job_recruit_edit(request, response, cookie, session, resource) {
    log(__filename, "do_content_job_recruit_edit");
    let self = this;
    let promise = new Promise(function(resolve, reject){
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
        let job = new T200Job();
  
        job.user_id = session.get("userid");
        job.city_id = session.get("cityid");
        job.title = request.get("title");
        job.content = request.get("content");
        
        if(T200HttpsForm.verify_id(job.user_id)
            && T200HttpsForm.verify_id(job.city_id)
            && T200HttpsForm.verify_text(job.title)
            && T200HttpsForm.verify_text(job.content)){
                job._table = "job_recruit";
                job._values = job.values();
                UserBiz.add(job).then(resolve, reject);
        }else{
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

