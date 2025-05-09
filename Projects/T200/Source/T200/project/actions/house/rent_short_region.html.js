const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserHouseRent = require('../../models/T200UserHouseRent.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_house_rent_short_region_list(request, response, cookie, session, resource) {
    log(__filename, "do_house_rent_short_region_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseRent();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let region_id = request.get("id");

        if(T200HttpsForm.verify_id(region_id)){
            house.region_id = region_id;
            house._fields = house.list_fields();
            house.merge_paging_count = house.merge_user_paging_short_region_count;
            house.merge_paging_list = house.merge_user_paging_short_region_list;
            UserBiz.paging2(house).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.region_id = region_id;
                data.paging = result.paging;
                data.houses = result.values;
                return view.render_file("house/rent_short_region.ejs", data).then(function (value) {
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


async function do_house_rent_short_region_search(request, response, cookie, session, resource) {
    log(__filename, "do_house_rent_short_region_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseRent();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let region_id = request.get("id");
        let search = request.get("search");

        if(T200HttpsForm.verify_id(region_id)
            && T200HttpsForm.verify_text(search)){
            house.region_id = region_id;
            house._search = search;
            house.flash_paging_fields();
            house.flash_fulltext_fields();
            house.merge_fulltext_count = house.merge_user_fulltext_short_region_count;
            house.merge_fulltext_list = house.merge_user_fulltext_short_region_list;
            UserBiz.fulltext2(house).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.region_id = region_id;
                data.paging = result.paging;
                data.houses = result.values;
                data.search = house._search;
                return view.render_file("house/rent_short_region.ejs", data).then(function (value) {
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


global.action.use_post('/house/rent/short/region/list', do_house_rent_short_region_list);
global.action.use_post('/house/rent/short/region/search', do_house_rent_short_region_search);