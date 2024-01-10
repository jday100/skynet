const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserExchange = require('../../models/T200UserExchange.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_exchange_list(request, response, cookie, session, resource) {
    log(__filename, "do_exchange_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200UserExchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        if(true){
            exchange.status = 1;
            exchange.flash_visitor_paging_fields();
            exchange.merge_paging_count = exchange.merge_user_paging_home_count;
            exchange.merge_paging_list = exchange.merge_user_paging_home_list;
            UserBiz.paging2(exchange).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.search = "";
                data.paging = result.paging;
                data.exchanges = result.values;
                return view.render_file("exchange/index.ejs", data).then(function (value) {
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
        }else{
            response.type("json");
            reject();
        }
  
    });

    return promise;
}


async function do_exchange_search(request, response, cookie, session, resource) {
    log(__filename, "do_exchange_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200UserExchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let search = request.get("search");

        if(T200HttpsForm.verify_text(search)){
            exchange._search = search;
            exchange.status = 1;
            exchange.flash_visitor_paging_fields();
            exchange.flash_visitor_fulltext_fields();
            exchange.merge_fulltext_count = exchange.merge_user_fulltext_type_count;
            exchange.merge_fulltext_list = exchange.merge_user_fulltext_type_list;
            UserBiz.fulltext2(exchange).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.exchanges = result.values;
                data.search = exchange._search;
                return view.render_file("exchange/index.ejs", data).then(function (value) {
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
        }else{
            response.type("json");
            reject();
        }
    });

    return promise;
}


global.action.use_post('/exchange/list', do_exchange_list);
global.action.use_post('/exchange/search', do_exchange_search);