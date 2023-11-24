const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200Exchange = require('../../../models/T200Exchange.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');


async function do_content_exchange_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200Exchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);


        exchange._fields = exchange.list_fields();
        exchange._order_direction = "DESC";
        UserBiz.paging(exchange).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.exchanges = result.values;
            return view.render_file("content/exchange/index.ejs", data).then(function (value) {
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

async function do_content_exchange_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200Exchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

 
        exchange._fields = exchange.fulltext_result_fields();
        exchange._search_fields = exchange.fulltext_fields();
        exchange._order_direction = "DESC";
        UserBiz.fulltext(exchange).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.exchanges = result.values;
            return view.render_file("content/exchange/index.ejs", data).then(function (value) {
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


global.action.use_post('/content/exchange/list', do_content_exchange_list);
global.action.use_post('/content/exchange/search', do_content_exchange_search);