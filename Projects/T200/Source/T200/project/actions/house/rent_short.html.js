const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserHouseRent = require('../../models/T200UserHouseRent.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_house_rent_short_list(request, response, cookie, session, resource) {
    log(__filename, "do_house_rent_short_list");
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

        let house = new T200UserHouseRent();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        if(true){
            house._fields = house.list_fields();
            house.merge_paging_count = house.merge_user_paging_short_count;
            house.merge_paging_list = house.merge_user_paging_short_list;
            UserBiz.paging2(house).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.houses = result.values;
                return view.render_file("house/rent_short.ejs", data).then(function (value) {
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

async function do_house_rent_short_search(request, response, cookie, session, resource) {
    log(__filename, "do_house_rent_short_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        if(global.setup.server){
            if(global.setup.server.search){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }

        let house = new T200UserHouseRent();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let search = request.get("search");

        if(T200HttpsForm.verify_text(search)){
            house._search = search;
            house.flash_paging_fields();
            house.flash_fulltext_fields();
            house.merge_fulltext_count = house.merge_user_fulltext_short_count;
            house.merge_fulltext_list = house.merge_user_fulltext_short_list;
            UserBiz.fulltext2(house).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.houses = result.values;
                data.search = house._search;
                return view.render_file("house/rent_short.ejs", data).then(function (value) {
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

global.action.use_post('/house/rent/short/list', do_house_rent_short_list);
global.action.use_post('/house/rent/short/search', do_house_rent_short_search);