const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserHouseRent = require('../../../models/T200UserHouseRent.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_content_house_rent_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_rent_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseRent();
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

        house.user_id = session.get("userid");

        if(true){
            house._fields = house.content_list_fields();
            house.paging_count_sql = house.merge_user_paging_count();
            house.merge_paging = house.merge_user_paging_list;
            UserBiz.paging(house).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.status = house.status;
                data.item_left = house.set_item_left();
                data.item_right = house.set_item_right();
                data.list_buttons = house.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/content/house/rent/list";
                list_box._search_url = "/content/house/rent/search";
                list_box._change_status_url = "/content/house/rent/list";

                return list_box.show(data).then(function(value){
                    response.type("json");
                    resolve(value);
                }, function(){
                    response.type("json");
                    reject();
                });
            }, function(){
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

async function do_content_house_rent_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_rent_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseRent();
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

        house.user_id = session.get("userid");

        if(T200HttpsForm.verify_id(house.user_id)
            //&& T200HttpsForm.verify_status(house.status)
            && T200HttpsForm.verify_text(search)){
                house.search = search;
                house._fields = house.content_list_fields();
                house._search_fields = house.content_fulltext_fields();
                house.fulltext_count_sql = house.merge_user_fulltext_count();
                house.merge_fulltext = house.merge_user_fulltext_list;
                UserBiz.fulltext(house).then(function(result){
                    let data = {};

                    data.paging = result.paging;
                    data.values = result.values;
                    data.status = house.status;
                    data.item_left = house.set_item_left();
                    data.item_right = house.set_item_right();
                    data.list_buttons = house.set_list_buttons();
    
                    let list_box = new T200ListView(resource);
    
                    list_box._list_url = "/content/house/rent/list";
                    list_box._search_url = "/content/house/rent/search";
                    list_box._change_status_url = "/content/house/rent/list";
    
                    return list_box.show(data).then(function(value){
                        response.type("json");
                        resolve(value);
                    }, function(){
                        response.type("json");
                        reject();
                    });
                }, function(){
                    response.type("json");
                    reject();
                });
        }else{
            response.type("json");
            reject(T200Error.build(1));
        }

    });

    return promise;
}


async function do_content_house_rent_publish(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_rent_publish");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseRent();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        house.user_id = session.get("userid");
        house.ids = request.get("ids");
        house.status = 1;

        if(T200HttpsForm.verify_id(house.user_id)
            && T200HttpsForm.verify_ids(house.ids)
            && T200HttpsForm.verify_id(house.status)){
            house._name_value = house.modify_status_array();
            UserBiz.modify(house.merge_user_status_update()).then(function(result){
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


async function do_content_house_rent_remove(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_rent_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseRent();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        house.user_id = session.get("userid");
        house.ids = request.get("ids");
        house.status = -1;

        if(T200HttpsForm.verify_id(house.user_id)
            && T200HttpsForm.verify_ids(house.ids)
            && T200HttpsForm.verify_status(house.status)){
            house._name_value = house.modify_status_array();
            UserBiz.modify(house.merge_user_status_update()).then(function(result){
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


global.action.use_post('/content/house/rent/list', do_content_house_rent_list);
global.action.use_post('/content/house/rent/search', do_content_house_rent_search);
global.action.use_post('/content/house/rent/publish', do_content_house_rent_publish);
global.action.use_post('/content/house/rent/remove', do_content_house_rent_remove);