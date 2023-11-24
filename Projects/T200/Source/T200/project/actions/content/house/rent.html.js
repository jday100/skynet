const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200House = require('../../../models/T200House.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');


async function do_content_house_rent_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_rent_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200House();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        house._table = "house_rent";
        house._fields = house.list_fields();
        house._order_direction = "DESC";
        UserBiz.paging(house).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.houses = result.values;
            return view.render_file("content/house/rent_index.ejs", data).then(function (value) {
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

async function do_content_house_rent_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_rent_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200House();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        house._table = "house_rent";
        house._fields = house.fulltext_result_fields();
        house._search_fields = house.fulltext_fields();
        house._order_direction = "DESC";
        UserBiz.fulltext(house).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.houses = result.values;
            return view.render_file("content/house/rent_index.ejs", data).then(function (value) {
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


global.action.use_post('/content/house/rent/list', do_content_house_rent_list);
global.action.use_post('/content/house/rent/search', do_content_house_rent_search);