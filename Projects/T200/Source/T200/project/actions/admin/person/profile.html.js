const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminPerson = require('../../../models/T200AdminPerson.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_person_profile(request, response, cookie, session, resource) {
    log(__filename, "do_admin_person_profile");
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

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){
            person.flash_admin_paging_fields();
            person.merge_paging_count = person.merge_admin_person_paging_count;
            person.merge_paging_list = person.merge_admin_person_paging_list;
            AdminBiz.paging2(person).then(function(result){
                let data = {};

                data.paging = result.paging;
                data.values = result.values;
                data.search = "";
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



global.action.use_post('/admin/person/profile', do_admin_person_profile);