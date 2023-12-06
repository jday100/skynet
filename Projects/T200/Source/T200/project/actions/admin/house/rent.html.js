const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminHouseRent = require('../../../models/T200AdminHouseRent.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_house_rent_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_house_rent_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200AdminHouseRent();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


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

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){
            house.flash_admin_paging_fields();
            house.merge_paging_count = house.merge_admin_paging_count;
            house.merge_paging_list = house.merge_admin_paging_list;
            AdminBiz.paging2(house).then(function(result){
                let data = {};
                
                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
                data.status = house.status;

                data.item_left = house.set_item_left();
                data.item_right = house.set_item_right();
                data.list_buttons = house.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/house/rent/list";
                list_box._search_url = "/admin/house/rent/search";
                list_box._change_status_url = "/admin/house/rent/list";

                return list_box.show(data).then(function(value){
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
            response.type("json");
            reject(T200Error.build(1));
        }
    
    });

    return promise;
}

async function do_admin_house_rent_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_house_rent_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200AdminHouseRent();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


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

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_text(search)){
            house._search = search;
            house.flash_admin_paging_fields();
            house.flash_admin_fulltext_fields();
            house.merge_fulltext_count = house.merge_admin_fulltext_count;
            house.merge_fulltext_list = house.merge_admin_fulltext_list;
            AdminBiz.fulltext2(house).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.search = house._search;
                data.status = house.status;

                data.item_left = house.set_item_left();
                data.item_right = house.set_item_right();
                data.list_buttons = house.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/house/rent/list";
                list_box._search_url = "/admin/house/rent/search";
                list_box._change_status_url = "/admin/house/rent/list";
    
                return list_box.show(data).then(function(value){
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
            response.type("json");
            reject(T200Error.build(1));
        }
    });

    return promise;
}


async function do_admin_house_rent_approve(request, response, cookie, session, resource) {
    log(__filename, "do_admin_house_rent_approve");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200AdminHouseRent();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");
        house.ids = request.get("ids");
        house.status = 1;

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_ids(house.ids)
            && T200HttpsForm.verify_id(house.status)){
            house.flash_admin_status_update();
            AdminBiz.modify(house.merge_admin_status_update()).then(function(){
                response.type("json");
                resolve();
            }, function (err) {
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


async function do_admin_house_rent_remove(request, response, cookie, session, resource) {
    log(__filename, "do_admin_house_rent_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200AdminHouseRent();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");
        house.ids = request.get("ids");
        house.status = -1;

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_ids(house.ids)
            && T200HttpsForm.verify_status(house.status)){
            house.flash_admin_status_update();
            AdminBiz.modify(house.merge_admin_status_update()).then(function(){
                response.type("json");
                resolve();
            }, function (err) {
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


global.action.use_post('/admin/house/rent/list', do_admin_house_rent_list);
global.action.use_post('/admin/house/rent/search', do_admin_house_rent_search);
global.action.use_post('/admin/house/rent/approve', do_admin_house_rent_approve);
global.action.use_post('/admin/house/rent/remove', do_admin_house_rent_remove);