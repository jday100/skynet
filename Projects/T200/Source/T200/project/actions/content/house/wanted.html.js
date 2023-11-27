const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200House = require('../../../models/T200House.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');


async function do_content_house_wanted_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_wanted_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200House();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        house._table = "house_wanted";
        house._fields = house.list_fields();
        house._order_direction = "DESC";
        house.paging_count_sql = house.merge_count();
        house.paging_list_sql = house.merge_paging();
        UserBiz.paging(house).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.houses = result.values;
            return view.render_file("content/house/wanted_index.ejs", data).then(function (value) {
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
    
    });

    return promise;
}

async function do_content_house_wanted_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_wanted_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200House();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

 
        house._fields = house.fulltext_result_fields();
        house._search_fields = house.fulltext_fields();
        house._order_direction = "DESC";
        UserBiz.fulltext(house).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.houses = result.values;
            return view.render_file("content/house/wanted/index.ejs", data).then(function (value) {
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

    });

    return promise;
}


global.action.use_post('/content/house/wanted/list', do_content_house_wanted_list);
global.action.use_post('/content/house/wanted/search', do_content_house_wanted_search);