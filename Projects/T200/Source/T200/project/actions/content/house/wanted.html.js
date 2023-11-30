const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserHouseWanted = require('../../../models/T200UserHouseWanted.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_content_house_wanted_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_wanted_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let status = request.get("status");

        switch(status){
            case '1':
                house.status = request.get("status1");
                break;
            case '2':
                house.status = request.get("status2");
                break;
            default:
                house.status = status;
        }

        house._fields = house.list_status_fields();
        house._order_direction = "DESC";
        house.paging_count_sql = house.merge_status_count(house.status);
        house.merge_paging = house.merge_status_paging_test;
        UserBiz.paging(house).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.values = result.values;
            data.status = house.status;
            let list = new T200ListView(resource);

            list._list_url = "/content/house/wanted/list";
            list._search_url = "/content/house/wanted/search";
            list._change_status_url = "/content/house/wanted/list";

            data.item_left = house.set_item_left();
            data.item_right = house.set_item_right();
            data.list_buttons = house.set_list_buttons();

            return list.show(data).then(function(value){
                response.type("json");
                resolve(value);
            }, function(){
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
        let house = new T200UserHouseWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

 
        let status = request.get("status");
        let search = request.get("search");

        switch(status){
            case '1':
                house.status = request.get("status1");
                break;
            case '2':
                house.status = request.get("status2");
                break;
            default:
                house.status = status;
        }

        if(T200HttpsForm.verify_text(search)){
            house._search = search;
            house._fields = house.fulltext_result_fields();
            house._search_fields = house.fulltext_fields();
            house._order_direction = "DESC";
            house.fulltext_count_sql = house.merge_fulltext_count(house.status, search);
   
            house.merge_paging = house.merge_fulltext_test;
            UserBiz.fulltext(house).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.values = result.values;
                data.status = house.status;

                let list = new T200ListView(resource);

                list._list_url = "/content/house/wanted/list";
                list._search_url = "/content/house/wanted/search";
                list._change_status_url = "/content/house/wanted/list";

                data.item_left = house.set_item_left();
                data.item_right = house.set_item_right();
                data.list_buttons = house.set_list_buttons();
    
                return list.show(data).then(function(value){
                    response.type("json");
                    resolve(value);
                }, function(){
                    response.type("json");
                    reject();
                });
     
            }, function (err) {
                response.type("json");
                reject();
            });

        }else{
            reject(T200Error.build(1));
        }

    });

    return promise;
}


async function do_content_house_wanted_publish(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_wanted_publish");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        house.ids = request.get("ids");
        house.status = 1;

        if(T200HttpsForm.verify_ids(house.ids)
            && T200HttpsForm.verify_id(house.status)){
            
            UserBiz.modify(house.merge_status_update()).then(function(result){
                if(result){
                    response.type("json");
                    resolve();
                }else{
                    response.type("json");
                    reject();
                }
            }, function (err) {
                response.type("json");
                reject();
            });

        }else{
            reject(T200Error.build(1));
        }
    });

    return promise;
}


async function do_content_house_wanted_remove(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_wanted_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        house.ids = request.get("ids");
        house.status = -1;

        if(T200HttpsForm.verify_ids(house.ids)
            && T200HttpsForm.verify_status(house.status)){
            
            UserBiz.modify(house.merge_status_update()).then(function(result){
                if(result){
                    response.type("json");
                    resolve();
                }else{
                    response.type("json");
                    reject();
                }
            }, function (err) {
                response.type("json");
                reject();
            });

        }else{
            reject(T200Error.build(1));
        }
    });

    return promise;
}


global.action.use_post('/content/house/wanted/list', do_content_house_wanted_list);
global.action.use_post('/content/house/wanted/search', do_content_house_wanted_search);
global.action.use_post('/content/house/wanted/publish', do_content_house_wanted_publish);
global.action.use_post('/content/house/wanted/remove', do_content_house_wanted_remove);