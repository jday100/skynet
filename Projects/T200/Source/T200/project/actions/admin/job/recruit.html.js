const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200Job = require('../../../models/T200Job.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');


async function do_admin_job_recruit_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_job_recruit_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200Job();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        job._table = "job_recruit";
        job._fields = job.list_fields();
        job._order_direction = "DESC";
        AdminBiz.paging(job).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.jobs = result.values;
            return view.render_file("admin/job/recruit_index.ejs", data).then(function (value) {
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
    
    });

    return promise;
}

async function do_admin_job_recruit_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_job_recruit_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200Job();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        job._table = "job_recruit";
        job._fields = job.fulltext_result_fields();
        job._search_fields = job.fulltext_fields();
        job._order_direction = "DESC";
        AdminBiz.fulltext(job).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.jobs = result.values;
            return view.render_file("admin/job/recruit_index.ejs", data).then(function (value) {
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

    });

    return promise;
}


global.action.use_post('/admin/job/recruit/list', do_admin_job_recruit_list);
global.action.use_post('/admin/job/recruit/search', do_admin_job_recruit_search);