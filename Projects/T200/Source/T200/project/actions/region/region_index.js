const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200HomeCityIndex = require('../../biz/T200HomeCityIndex.js');
const T200HomeRegionIndex = require('../../biz/T200HomeRegionIndex.js');


async function do_region_index(request, response, cookie, session, resource) {
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let view = new T200HomeView(resource);
        let HomeIndex = new T200HomeRegionIndex(request, cookie, session);

        let region_id = request.get("id");

        if(T200HttpsForm.verify_id(region_id)){
            return HomeIndex.load_index(region_id).then(function(data){
                data.region_id = region_id;
                return view.render_file('region/region.ejs', data);
            }, function(err){
                return error();
            }).then(function(result){
                response.success(result);
                resolve(result);
            }, function(err){
                reject(err);
                return error();
            });
        }else{
            reject();
        } 

    });

    return promise;
}

async function do_city_index(request, response, cookie, session, resource) {
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let view = new T200HomeView(resource);
        let HomeIndex = new T200HomeCityIndex(request, cookie, session);

        let city_id = request.get("id");

        if(T200HttpsForm.verify_id(city_id)){
            return HomeIndex.load_index(city_id).then(function(data){
                data.city_id = city_id;
                return view.render_file('region/city.ejs', data);
            }, function(err){
                return error();
            }).then(function(result){
                response.success(result);
                resolve(result);
            }, function(err){
                reject(err);
                return error();
            });
        }else{
            reject();
        }       

    });

    return promise;
}


module.exports = { do_region_index, do_city_index };