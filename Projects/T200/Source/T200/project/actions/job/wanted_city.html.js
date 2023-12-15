const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');

const T200HomeJobWantedCityIndex = require('../../biz/T200HomeJobWantedCityIndex.js');


async function do_job_wanted_city_list(request, response, cookie, session, resource) {
    log(__filename, "do_job_wanted_city_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let view = new T200HomeView(resource);
        let JobWantedIndex = new T200HomeJobWantedCityIndex(request, cookie, session);

        let city_id = request.get("id");

        if(T200HttpsForm.verify_id(city_id)){
            return JobWantedIndex.load_index().then(function(data){
                data.city_id = city_id;
                return view.render_file('job/wanted_city.ejs', data);
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
        }else{
            response.type("json");
            reject(err);
        }
    });

    return promise;
}


global.action.use_post('/job/wanted/city/list', do_job_wanted_city_list);