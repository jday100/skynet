const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserJobRecruit = require('../../models/T200UserJobRecruit.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_job_recruit_full_list(request, response, cookie, session, resource) {
    log(__filename, "do_job_recruit_full_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200UserJobRecruit();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        if(true){
            job._fields = job.list_fields();
            job.paging_count_sql = job.merge_user_paging_type_count();
            job.merge_paging = job.merge_user_paging_type_list;
            UserBiz.paging(job).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.jobs = result.values;
                return view.render_file("job/recruit_full.ejs", data).then(function (value) {
                    response.type("json");
                    resolve(value);
                }, function (err) {
                    response.type("json");
                    reject();
                });
            }, function (err) {
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


global.action.use_post('/job/recruit/full', do_job_recruit_full_list);