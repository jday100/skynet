const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserJobWanted = require('../../models/T200UserJobWanted.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_job_wanted_part_city_list(request, response, cookie, session, resource) {
    log(__filename, "do_job_wanted_part_city_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200UserJobWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let city_id = request.get("id");

        if(T200HttpsForm.verify_id(city_id)){
            job.city_id = city_id;
            job._fields = job.list_fields();
            job.paging_count_sql = job.merge_user_paging_type_count();
            job.merge_paging = job.merge_user_paging_type_list;
            UserBiz.paging(job).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.city_id = city_id;
                data.paging = result.paging;
                data.jobs = result.values;
                return view.render_file("job/wanted_part_city.ejs", data).then(function (value) {
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


global.action.use_post('/job/wanted/part/city', do_job_wanted_part_city_list);