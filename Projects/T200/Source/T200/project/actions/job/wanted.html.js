const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');

const T200HomeJobWantedIndex = require('../../biz/T200HomeJobWantedIndex.js');


async function do_job_wanted_list(request, response, cookie, session, resource) {
    log(__filename, "do_job_wanted_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        if(global.setup.server){
            if(global.setup.server.list){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }

        let view = new T200HomeView(resource);
        let JobWantedIndex = new T200HomeJobWantedIndex(request, cookie, session);

        return JobWantedIndex.load_index().then(function(data){
            return view.render_file('job/wanted.ejs', data);
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


global.action.use_post('/job/wanted/list', do_job_wanted_list);