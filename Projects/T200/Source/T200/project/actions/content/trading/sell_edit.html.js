const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200Trading = require('../../../models/T200Trading.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

async function do_content_trading_sell_edit(request, response, cookie, session, resource) {
    log(__filename, "do_content_trading_sell_edit");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let UserBiz = new T200HomeUserBiz(request, cookie, session);


        let sid = cookie.get("sid");
        if(sid && 0 < sid){
            do_content_trading_sell_modify(request, response, cookie, session, resource, UserBiz);
        }else{
            do_content_trading_sell_add(request, response, cookie, session, resource, UserBiz).then(function(){
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

async function do_content_trading_sell_add(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_trading_sell_add");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let trading = new T200Trading();
  
        trading.user_id = session.get("userid");
        trading.title = request.get("title");
        trading.content = request.get("content");
        
        if(T200HttpsForm.verify_id(trading.user_id)
            && T200HttpsForm.verify_text(trading.title)
            && T200HttpsForm.verify_text(trading.content)){
                trading._table = "trading_sell";
                trading._values = trading.values();
                UserBiz.add(trading).then(resolve, reject);
        }
    });

    return promise;
}

async function do_content_trading_sell_modify(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_trading_sell_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}


global.action.use_post('/content/trading/sell/edit', do_content_trading_sell_edit);

