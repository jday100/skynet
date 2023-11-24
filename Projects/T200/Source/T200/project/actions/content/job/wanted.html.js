const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200Job = require('../../../models/T200Job.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');


async function do_content_job_wanted_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_job_wanted_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200Job();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        job._table = "job_wanted";
        job._fields = job.list_fields();
        job._order_direction = "DESC";
        UserBiz.paging(job).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.jobs = result.values;
            return view.render_file("content/job/wanted_index.ejs", data).then(function (value) {
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

async function do_content_job_wanted_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_job_wanted_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200Job();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        job._table = "job_wanted";
        job._fields = job.fulltext_result_fields();
        job._search_fields = job.fulltext_fields();
        job._order_direction = "DESC";
        UserBiz.fulltext(job).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.jobs = result.values;
            return view.render_file("content/job/wanted_index.ejs", data).then(function (value) {
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


global.action.use_post('/content/job/wanted/list', do_content_job_wanted_list);
global.action.use_post('/content/job/wanted/search', do_content_job_wanted_search);