const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200AdminExchange = require('../../../models/T200AdminExchange.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_admin_global(request, response, cookie, session, resource) {
    log(__filename, "do_admin_global");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200AdminExchange();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){

            AdminBiz.list().then(function(){
                let view = new T200HomeView(resource);
                let data = {};

                return view.render_file("admin/global/global.ejs", data).then(function(value){
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



global.action.use_post('/admin/global', do_admin_global);
