const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200Exchange = require('../../../models/T200Exchange.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');


async function do_admin_exchange_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_exchange_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200Exchange();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);


        exchange._fields = exchange.list_fields();
        exchange._order_direction = "DESC";
        AdminBiz.paging(exchange).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.exchanges = result.values;
            return view.render_file("admin/exchange/index.ejs", data).then(function (value) {
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

async function do_admin_exchange_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_exchange_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200Exchange();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

 
        exchange._fields = exchange.fulltext_result_fields();
        exchange._search_fields = exchange.fulltext_fields();
        exchange._order_direction = "DESC";
        AdminBiz.fulltext(exchange).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.exchanges = result.values;
            return view.render_file("admin/exchange/index.ejs", data).then(function (value) {
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


global.action.use_post('/admin/exchange/list', do_admin_exchange_list);
global.action.use_post('/admin/exchange/search', do_admin_exchange_search);