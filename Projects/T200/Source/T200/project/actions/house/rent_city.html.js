const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');

const T200HomeHouseRentCityIndex = require('../../biz/T200HomeHouseRentCityIndex.js');


async function do_house_rent_city_list(request, response, cookie, session, resource) {
    log(__filename, "do_house_rent_city_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let view = new T200HomeView(resource);
        let HouseRentIndex = new T200HomeHouseRentCityIndex(request, cookie, session);

        let city_id = request.get("id");

        if(T200HttpsForm.verify_id(city_id)){
            return HouseRentIndex.load_index(city_id).then(function(data){
                data.city_id = city_id;
                return view.render_file('house/rent_city.ejs', data);
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


global.action.use_post('/house/rent/city/list', do_house_rent_city_list);