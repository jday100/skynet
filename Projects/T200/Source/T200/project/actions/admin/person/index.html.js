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

        person._fields = person.list_status_fields();
        person._order_direction = "DESC";
        person.paging_count_sql = person.merge_status_count(person.status);
        person.merge_paging = person.merge_status_paging_test;
        AdminBiz.paging(person).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.values = result.values;
            data.status = person.status;
            let list = new T200ListView(resource);

            list._list_url = "/admin/person/list";
            list._search_url = "/admin/person/search";
            list._change_status_url = "/admin/person/list";

            data.item_left = person.set_item_left();
            data.item_right = person.set_item_right();
            data.list_buttons = person.set_list_buttons();

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

        if(T200HttpsForm.verify_text(search)){
            person._search = search;
            person._fields = person.fulltext_result_fields();
            person._search_fields = person.fulltext_fields();
            person._order_direction = "DESC";
            person.fulltext_count_sql = person.merge_fulltext_count(person.status, search);
   
            person.merge_paging = person.merge_fulltext_test;
            AdminBiz.fulltext(person).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.values = result.values;
                data.status = person.status;

                let list = new T200ListView(resource);

                list._list_url = "/admin/person/list";
                list._search_url = "/admin/person/search";
                list._change_status_url = "/admin/person/list";

                data.item_left = person.set_item_left();
                data.item_right = person.set_item_right();
                data.list_buttons = person.set_list_buttons();
    
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


async function do_admin_person_approve(request, response, cookie, session, resource) {
    log(__filename, "do_admin_person_approve");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200AdminPerson();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        person.ids = request.get("ids");
        person.status = 1;

        if(T200HttpsForm.verify_ids(person.ids)
            && T200HttpsForm.verify_id(person.status)){
            
            AdminBiz.modify(person.merge_status_update()).then(function(result){
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

        person.ids = request.get("ids");
        person.status = -1;

        if(T200HttpsForm.verify_ids(person.ids)
            && T200HttpsForm.verify_status(person.status)){
            
            AdminBiz.modify(person.merge_status_update()).then(function(result){
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