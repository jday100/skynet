const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserHouseRent = require('../../models/T200UserHouseRent.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_house_rent_short_city_list(request, response, cookie, session, resource) {
    log(__filename, "do_house_rent_short_city_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseRent();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let city_id = request.get("id");

        if(T200HttpsForm.verify_id(city_id)){
            house.city_id = city_id;
            house._fields = house.list_fields();
            house.merge_paging_count = house.merge_user_paging_short_city_count;
            house.merge_paging_list = house.merge_user_paging_short_city_list;
            UserBiz.paging2(house).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.city_id = city_id;
                data.paging = result.paging;
                data.houses = result.values;
                return view.render_file("house/rent_short_city.ejs", data).then(function (value) {
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


global.action.use_post('/house/rent/short/city/list', do_house_rent_short_city_list);