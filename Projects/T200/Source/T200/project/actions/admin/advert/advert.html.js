const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminSetting = require('../../../models/T200AdminSetting.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_advert_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_global");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let setting = new T200AdminSetting();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){
            setting.setting_id = 1000000;
            setting.flash_admin_list_fields();
            AdminBiz.load(setting.merge_admin_setting_by_id()).then(function(result){
                let view = new T200HomeView(resource);
                let data = JSON.parse(result.content);

                data.id = result.id;

                return view.render_file("admin/global/global.ejs", data).then(function(value){
                    response.type("json");
                    resolve(value);
                }, function(){
                    response.type("json");
                    reject();
                });
            }, function(){
                let view = new T200HomeView(resource);
                let data = {};

                data.id = 0;
                data.site = true;
                data.register = true;
                data.login = true;
                data.publish = true;
                data.reply = true;
                data.list = true;
                data.search = true;
                data.board = true;

                return view.render_file("admin/global/global.ejs", data).then(function(value){
                    response.type("json");
                    resolve(value);
                }, function(){
                    response.type("json");
                    reject();
                });
            });
        }else{
            response.type("json");
            reject(T200Error.build(1));
        }
    
    });

    return promise;
}


async function do_admin_advert_save(request, response, cookie, session, resource) {
    log(__filename, "do_admin_global");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let setting = new T200AdminSetting();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){
            setting.setting_id = 1000000;
            setting.flash_admin_list_fields();
            AdminBiz.load(setting.merge_admin_setting_by_id()).then(function(result){
                let view = new T200HomeView(resource);
                let data = JSON.parse(result.content);

                data.id = result.id;

                return view.render_file("admin/global/global.ejs", data).then(function(value){
                    response.type("json");
                    resolve(value);
                }, function(){
                    response.type("json");
                    reject();
                });
            }, function(){
                let view = new T200HomeView(resource);
                let data = {};

                data.id = 0;
                data.site = true;
                data.register = true;
                data.login = true;
                data.publish = true;
                data.reply = true;
                data.list = true;
                data.search = true;
                data.board = true;

                return view.render_file("admin/global/global.ejs", data).then(function(value){
                    response.type("json");
                    resolve(value);
                }, function(){
                    response.type("json");
                    reject();
                });
            });
        }else{
            response.type("json");
            reject(T200Error.build(1));
        }
    
    });

    return promise;
}



global.action.use_post('/admin/advert/list', do_admin_advert_list);
global.action.use_post('/admin/advert/save', do_admin_advert_save);
