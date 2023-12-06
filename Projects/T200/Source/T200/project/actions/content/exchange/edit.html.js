const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200UserExchange = require('../../../models/T200UserExchange.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

async function do_content_exchange_edit(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_edit");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let UserBiz = new T200HomeUserBiz(request, cookie, session);


        let eid = cookie.get("eid");
        if(eid && 0 < eid){
            do_content_exchange_modify(request, response, cookie, session, resource, UserBiz);
        }else{
            do_content_exchange_add(request, response, cookie, session, resource, UserBiz).then(function(){
                response.type("json");
                resolve();
            }, function(err){
                response.type("json");
                reject();
            });
        }
  
    });

    return promise;
}

async function do_content_exchange_add(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_exchange_add");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let exchange = new T200UserExchange();
  
        exchange.user_id = session.get("userid");
        exchange.status = session.get("status");
        exchange.city_id = session.get("cityid");
        exchange.title = request.get("title");
        exchange.content = request.get("content");
        
        if(T200HttpsForm.verify_id(exchange.user_id)
            && T200HttpsForm.verify_id(exchange.status)
            && T200HttpsForm.verify_id(exchange.city_id)
            && T200HttpsForm.verify_text(exchange.title)
            && T200HttpsForm.verify_text(exchange.content)){
                exchange.flash_content_append_fields();
                exchange.flash_content_append_values();
                UserBiz.append(exchange.merge_user_insert()).then(resolve, reject);
        }
    });

    return promise;
}

async function do_content_exchange_modify(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_exchange_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}


global.action.use_post('/content/exchange/edit', do_content_exchange_edit);

