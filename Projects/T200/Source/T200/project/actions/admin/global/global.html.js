const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminSetting = require('../../../models/T200AdminSetting.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_global(request, response, cookie, session, resource) {
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

                data.id = 0;

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
                data.site = false;
                data.register = false;
                data.login = false;
                data.publish = false;
                data.reply = false;
                data.list = false;
                data.search = false;
                data.board = false;

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


async function do_admin_global_save(request, response, cookie, session, resource) {
    log(__filename, "do_admin_global_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let setting = new T200AdminSetting();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");
        let id = request.get("id");

        if(T200HttpsForm.verify_id(user_id)){
            if(id && 0 < id){
                do_admin_setting_modify(request, response, cookie, session, resource, AdminBiz);
            }else{
                do_admin_setting_append(request, response, cookie, session, resource, AdminBiz).then(function(){
                    response.type("json");
                    resolve();
                }, function(err){
                    response.type("json");
                    reject();
                });
            }
        }else{
            response.type("json");
            reject(T200Error.build(1));
        }
    
    });

    return promise;
}


async function do_admin_setting_append(request, response, cookie, session, resource, AdminBiz) {
    log(__filename, "do_admin_setting_append");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let setting = new T200AdminSetting();
  
        let user_id = session.get("userid");

        setting.setting_id = 1000000;
        setting.status = 1;
        setting.name = "1000000";
        setting.content = "1";
        
        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_id(setting.setting_id)
            && T200HttpsForm.verify_id(setting.status)
            && T200HttpsForm.verify_text(setting.name)
            && T200HttpsForm.verify_text(setting.content)){
                setting.content = merge_json(request);
                setting.flash_admin_append_fields();
                setting.flash_admin_append_values();
                AdminBiz.append(setting.merge_admin_insert()).then(function(id){
                    resolve();
                }, function(){
                    reject();
                });
        }else{
            reject();
        }
    });

    return promise;
}

async function do_admin_setting_modify(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_admin_setting_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}

function merge_json(request) {
    let result;
    let obj = {};

    obj.site = request.get_bool("site");
    obj.register = request.get_bool("register");
    obj.login = request.get_bool("login");
    obj.publish = request.get_bool("publish");
    obj.reply = request.get_bool("reply");
    obj.list = request.get_bool("list");
    obj.search = request.get_bool("search");
    obj.board = request.get_bool("board");

    result = JSON.stringify(obj);
    return result;
}

global.action.use_post('/admin/global', do_admin_global);
global.action.use_post('/admin/global/save', do_admin_global_save);
