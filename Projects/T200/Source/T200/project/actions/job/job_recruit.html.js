const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserJobRecruit = require('../../models/T200UserJobRecruit.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_job_recruit_board(request, response, cookie, session, resource) {
    log(__filename, "do_job_recruit_board");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        if(global.setup.server){
            if(global.setup.server.board){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }

        let job = new T200UserJobRecruit();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let item = cookie.get("id");

        if(undefined == item){

        }else{
            job.id = item._value;
        }

        if(T200HttpsForm.verify_id(job.id)){
            job.flash_user_board_fields();
            job.merge_board_count = job.merge_user_board_count;
            job.merge_board_list = job.merge_user_board_list;
            UserBiz.board(job).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.jobs = result.values;
                return view.render_file("job/job_recruit.ejs", data).then(function (value) {
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



async function do_job_recruit_reply(request, response, cookie, session, resource) {
    log(__filename, "do_job_recruit_reply");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        if(global.setup.server){
            if(global.setup.server.reply){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }

        let job = new T200UserJobRecruit();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let nickname = request.get("nickname");

        job.user_id = session.get("userid");
        job.identity_id = session.get("identityid");
        job.city_id = session.get("cityid");
        job.parent_id = request.get("parentid");
        job.title = `@${nickname}`;
        job.content = request.get("content");
        job.status = 1;

        if(T200HttpsForm.verify_id(job.user_id)
            && T200HttpsForm.verify_id(job.identity_id)
            && T200HttpsForm.verify_id(job.city_id)
            && T200HttpsForm.verify_id(job.parent_id)
            && T200HttpsForm.verify_id(job.status)
            && T200HttpsForm.verify_text(nickname)
            && T200HttpsForm.verify_text(job.content)){
            job.flash_reply_fields();
            job.flash_reply_values();
            UserBiz.append(job.merge_user_insert()).then(function(){
                do_job_recruit_board_panel(job, UserBiz, cookie, resource).then(function(result){
                    response.type("json");
                    resolve(result);
                }, function(){
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


function do_job_recruit_board_panel(job, UserBiz, cookie, resource) {
    log(__filename, "do_job_recruit_board_panel");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let item = cookie.get("id");

        if(undefined == item){

        }else{
            job.id = item._value;
        }

        if(T200HttpsForm.verify_id(job.id)){
            job.flash_user_board_fields();
            job.merge_board_count = job.merge_user_board_count;
            job.merge_board_list = job.merge_user_board_list;
            UserBiz.board(job).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.jobs = result.values;
                return view.render_file("job/job_recruit.ejs", data).then(function (value) {
                    resolve(value);
                }, function (err) {
                    reject();
                });
            }, function (err) {
                reject();
            });
        }else{
            reject();
        }
  
    });

    return promise;
}


global.action.use_post('/job/recruit/board', do_job_recruit_board);
global.action.use_post('/job/recruit/reply', do_job_recruit_reply);