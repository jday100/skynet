const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminPerson = require('../../../models/T200AdminPerson.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_person_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_person_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200AdminPerson();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


        let status = request.get("status");

        switch(status){
            case '1':
                person.status = request.get("status1");
                break;
            case '2':
                person.status = request.get("status2");
                break;
            default:
                person.status = status;
        }

        person.user_id = session.get("userid");

        if(true){
            person._fields = person.admin_list_fields();
            person.paging_count_sql = person.merge_admin_person_paging_count();
            person.merge_paging = person.merge_admin_person_paging_list;
            AdminBiz.paging(person).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.status = person.status;
                data.item_left = person.set_item_left();
                data.item_right = person.set_item_right();
                data.list_buttons = person.set_list_buttons();

                let list_box = new T200ListView(resource);

                list_box._list_url = "/admin/person/list";
                list_box._search_url = "/admin/person/search";
                list_box._change_status_url = "/admin/person/list";

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

async function do_admin_person_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_person_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200AdminPerson();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

 
        let status = request.get("status");
        let search = request.get("search");

        switch(status){
            case '1':
                person.status = request.get("status1");
                break;
            case '2':
                person.status = request.get("status2");
                break;
            default:
                person.status = status;
        }

        person.user_id = session.get("userid");

        if(T200HttpsForm.verify_id(person.user_id)
            //&& T200HttpsForm.verify_status(person.status)
            && T200HttpsForm.verify_text(search)){
                person.username = search;
                person._fields = person.admin_list_fields();
                person.paging_count_sql = person.merge_admin_person_search_count();
                person.merge_paging = person.merge_admin_person_search_list;
                AdminBiz.paging(person).then(function(result){
                    let data = {};

                    data.paging = result.paging;
                    data.values = result.values;
                    data.status = person.status;
                    data.item_left = person.set_item_left();
                    data.item_right = person.set_item_right();
                    data.list_buttons = person.set_list_buttons();
    
                    let list_box = new T200ListView(resource);
    
                    list_box._list_url = "/admin/person/list";
                    list_box._search_url = "/admin/person/search";
                    list_box._change_status_url = "/admin/person/list";
    
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


async function do_admin_person_approve(request, response, cookie, session, resource) {
    log(__filename, "do_admin_person_approve");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200AdminPerson();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        person.user_id = session.get("userid");
        person.ids = request.get("ids");
        person.status = 1;

        if(T200HttpsForm.verify_id(person.user_id)
            && T200HttpsForm.verify_ids(person.ids)
            && T200HttpsForm.verify_id(person.status)){
            person._name_value = person.modify_status_array();
            AdminBiz.modify(person.merge_admin_status_update()).then(function(result){
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


async function do_admin_person_remove(request, response, cookie, session, resource) {
    log(__filename, "do_admin_person_remove");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200AdminPerson();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        person.user_id = session.get("userid");
        person.ids = request.get("ids");
        person.status = -1;

        if(T200HttpsForm.verify_id(person.user_id)
            && T200HttpsForm.verify_ids(person.ids)
            && T200HttpsForm.verify_status(person.status)){
            person._name_value = person.modify_status_array();
            AdminBiz.modify(person.merge_admin_status_update()).then(function(result){
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



global.action.use_post('/admin/person/list', do_admin_person_list);
global.action.use_post('/admin/person/search', do_admin_person_search);
global.action.use_post('/admin/person/approve', do_admin_person_approve);
global.action.use_post('/admin/person/remove', do_admin_person_remove);