const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200UserHouseWanted = require('../../../models/T200UserHouseWanted.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

async function do_content_house_wanted_edit(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_wanted_edit");
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


        let wid = cookie.get("wid");
        if(wid && 0 < wid){
            do_content_house_wanted_modify(request, response, cookie, session, resource, UserBiz);
        }else{
            do_content_house_wanted_add(request, response, cookie, session, resource, UserBiz).then(function(){
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

async function do_content_house_wanted_add(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_house_wanted_add");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseWanted();
  
        house.user_id = session.get("userid");
        house.identity_id = session.get("identityid");
        house.status = session.get("status");
        house.continent_id = session.get("continentid");
        house.continent_name = session.get("continent");
        house.region_id = session.get("regionid");
        house.region_name = session.get("region");
        house.city_id = session.get("cityid");
        house.city_name = session.get("city");
        house.title = request.get("title");
        house.content = request.get("content");

        let type = request.get("type");

        if(1 == type){
            house.type_long = 1;
            house.type_short = 0;
        }else if(2 == type){
            house.type_long = 0;
            house.type_short = 1;
        }else if(0 == type){
            house.type_long = 1;
            house.type_short = 1;
        }
        
        if(T200HttpsForm.verify_id(house.user_id)
            && T200HttpsForm.verify_id(house.identity_id)
            && T200HttpsForm.verify_id(house.status)
            && T200HttpsForm.verify_id(house.continent_id)
            && T200HttpsForm.verify_text(house.continent_name)
            && T200HttpsForm.verify_id(house.region_id)
            && T200HttpsForm.verify_text(house.region_name)
            && T200HttpsForm.verify_id(house.city_id)
            && T200HttpsForm.verify_text(house.city_name)
            && T200HttpsForm.verify_text(house.title)
            && T200HttpsForm.verify_text(house.content)){
                house.flash_content_append_fields();
                house.flash_content_append_values();
                UserBiz.append(house.merge_user_insert()).then(function(id){
                    house.parent_id = id;
                    house.id = id;
                    if(T200HttpsForm.verify_id(house.parent_id)){
                        house.flash_content_parent_update();
                        UserBiz.modify(house.merge_update_by_key()).then(function(){
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
            reject();
        }
    });

    return promise;
}

async function do_content_house_wanted_modify(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_house_wanted_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}


global.action.use_post('/content/house/wanted/edit', do_content_house_wanted_edit);

