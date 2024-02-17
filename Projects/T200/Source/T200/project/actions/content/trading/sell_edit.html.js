const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200UserTradingSell = require('../../../models/T200UserTradingSell.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

async function do_content_trading_sell_edit(request, response, cookie, session, resource) {
    log(__filename, "do_content_trading_sell_edit");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        if(global.setup.server){
            if(global.setup.server.publish){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }
        
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
        let trading = new T200UserTradingSell();
  
        trading.user_id = session.get("userid");
        trading.identity_id = session.get("identityid");
        trading.status = session.get("status");
        trading.continent_id = session.get("continentid");
        trading.continent_name = session.get("continent");
        trading.region_id = session.get("regionid");
        trading.region_name = session.get("region");
        trading.city_id = session.get("cityid");
        trading.city_name = session.get("city");
        trading.title = request.get("title");
        trading.content = request.get("content");
        
        if(T200HttpsForm.verify_id(trading.user_id)
            && T200HttpsForm.verify_id(trading.identity_id)
            && T200HttpsForm.verify_id(trading.status)
            && T200HttpsForm.verify_id(trading.continent_id)
            && T200HttpsForm.verify_text(trading.continent_name)
            && T200HttpsForm.verify_id(trading.region_id)
            && T200HttpsForm.verify_text(trading.region_name)
            && T200HttpsForm.verify_id(trading.city_id)
            && T200HttpsForm.verify_text(trading.city_name)
            && T200HttpsForm.verify_text(trading.title)
            && T200HttpsForm.verify_text(trading.content)){
                trading.flash_content_append_fields();
                trading.flash_content_append_values();
                UserBiz.append(trading.merge_user_insert()).then(function(id){
                    trading.parent_id = id;
                    trading.id = id;
                    if(T200HttpsForm.verify_id(trading.parent_id)){
                        trading.flash_content_parent_update();
                        UserBiz.modify(trading.merge_update_by_key()).then(function(){
                            response.type("json");
                            resolve();
                        }, function(){
                            response.type("json");
                            reject();
                        });
                    }
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

async function do_content_trading_sell_modify(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_trading_sell_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}


global.action.use_post('/content/trading/sell/edit', do_content_trading_sell_edit);

