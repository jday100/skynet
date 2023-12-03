const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserJobWanted = require('../../models/T200UserJobWanted.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_job_wanted_board(request, response, cookie, session, resource) {
    log(__filename, "do_job_wanted_board");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let job = new T200UserJobWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let item = cookie.get("id");

        if(undefined == item){

        }else{
            job.id = item._value;
        }

        if(T200HttpsForm.verify_id(job.id)){
            job._fields = job.board_fields();
            job.board_count_sql = job.merge_board_count(job.id);
            job.merge_board = job.merge_board_list;
            UserBiz.board(job).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.jobs = result.values;
                return view.render_file("job/job_wanted.ejs", data).then(function (value) {
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


global.action.use_post('/job/wanted/board', do_job_wanted_board);