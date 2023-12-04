const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');

const T200HomeJobIndex = require('../../biz/T200HomeJobIndex.js');


async function do_job_list(request, response, cookie, session, resource) {
    log(__filename, "do_job_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let view = new T200HomeView(resource);
        let JobIndex = new T200HomeJobIndex(request, cookie, session);

        return JobIndex.load_index().then(function(data){
            return view.render_file('job/index.ejs', data);
        }, function(err){
            return error();
        }).then(function(result){
            response.type("json");
            response.success(result);
            resolve(result);
        }, function(err){
            response.type("json");
            reject(err);
            return error();
        });

    });

    return promise;
}


global.action.use_post('/job/list', do_job_list);