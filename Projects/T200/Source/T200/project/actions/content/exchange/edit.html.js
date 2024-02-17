const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const sharp = require('sharp');
const T200Path = require('../../../../library/fs/T200Path.js');
const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200UserExchange = require('../../../models/T200UserExchange.js');
const T200UserDatum = require('../../../models/T200UserDatum.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');
const T200Database = require('../../../../library/db/T200Database.js');

async function do_content_exchange_edit(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_edit");
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
        exchange.identity_id = session.get("identityid");
        exchange.parent_nickname = session.get("nickname");
        exchange.status = session.get("status");
        exchange.continent_id = session.get("continentid");
        exchange.continent_name = session.get("continent");
        exchange.region_id = session.get("regionid");
        exchange.region_name = session.get("region");
        exchange.city_id = session.get("cityid");
        exchange.city_name = session.get("city");
        exchange.title = request.get("title");
        exchange.content = request.get("content");
        
        if(T200HttpsForm.verify_id(exchange.user_id)
            && T200HttpsForm.verify_id(exchange.identity_id)
            && T200HttpsForm.verify_text(exchange.parent_nickname)
            && T200HttpsForm.verify_id(exchange.status)
            && T200HttpsForm.verify_id(exchange.continent_id)
            && T200HttpsForm.verify_text(exchange.continent_name)
            && T200HttpsForm.verify_id(exchange.region_id)
            && T200HttpsForm.verify_text(exchange.region_name)
            && T200HttpsForm.verify_id(exchange.city_id)
            && T200HttpsForm.verify_text(exchange.city_name)
            && T200HttpsForm.verify_text(exchange.title)
            && T200HttpsForm.verify_text(exchange.content)){
                exchange.flash_content_append_fields();
                exchange.flash_content_append_values();
                UserBiz.append(exchange.merge_user_insert()).then(function(id){
                    exchange.parent_id = id;
                    exchange.id = id;
                    if(T200HttpsForm.verify_id(exchange.parent_id)){
                        exchange.flash_content_parent_update();
                        UserBiz.modify(exchange.merge_update_by_key()).then(function(){
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

async function do_content_exchange_modify(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_exchange_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}


async function do_content_exchange_upload(request, response, cookie, session, resource) {
    log(__filename, "do_content_exchange_upload");
    let self = this;
    let promise = new Promise(async function(resolve, reject){
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let user_id = session.get("userid");
        let files = request.get_files();

        if(user_id && 0 < user_id && files && 0 < files.file.length){
            let result = false;
            let data = new Array();
            for(let item of files.file){

                (async function(item){
                    let datum = new T200UserDatum();
                
                    datum.user_id = user_id;
                    datum.name = `${user_id}/${item.newFilename}`;
                    datum.filename = item.originalFilename;

                    let file = T200Path.join_root(`storages/${datum.name}`);
                    let target = T200Path.join_root(`storages/${user_id}/${item.originalFilename}`);

                    await sharp(file).resize(800, null).toFile(target, async function(err, info){
                        if(err){

                        }else{
                            datum.fullpath = target;
                            datum.flash_content_append_fields();
                            datum.flash_content_append_values();
                            await UserBiz.append(datum.merge_insert()).then(function(){
                                result = true;
                                data.push(datum.name);
                            }, function(){
                                result = false;
                            });
            
                        }
                    });
                })(item);
                
                
                if(!result)break;
            }

            if(result){
                response.type("json");
                resolve(data);
            }else{
                response.type("json");
                reject(data);
            }
        }else{
            response.type("json");
            reject();
        }

    });

    return promise;
}

global.action.use_post('/content/exchange/edit', do_content_exchange_edit);
global.action.use_post('/content/exchange/upload', do_content_exchange_upload);

