const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserExchange = require('../../../models/T200UserExchange.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

const T200ListView = require('../../../../library/web/view/T200ListView.js');


async function do_content_exchange_list(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200UserExchange();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);


        let status = request.get("status");

        switch(status){
            case '1':
                exchange.status = request.get("status1");
                break;
            case '2':
                exchange.status = request.get("status2");
                break;
            default:
                exchange.status = status;
        }

        exchange._fields = exchange.list_status_fields();
        exchange._order_direction = "DESC";
        exchange.paging_count_sql = exchange.merge_status_count(exchange.status);
        exchange.merge_paging = exchange.merge_status_paging_test;
        UserBiz.paging(exchange).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.values = result.values;
            data.status = exchange.status;
            let list = new T200ListView(resource);

            list._list_url = "/content/exchange/list";
            list._search_url = "/content/exchange/search";
            list._change_status_url = "/content/exchange/list";

            data.item_left = exchange.set_item_left();
            data.item_right = exchange.set_item_right();
            data.list_buttons = exchange.set_list_buttons();

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

async function do_content_exchange_search(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200UserExchange();
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