const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200House = require('../../../models/T200House.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');

async function do_content_house_rent_edit(request, response, cookie, session, resource) {
    log(__filename, "do_content_house_rent_edit");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let UserBiz = new T200HomeUserBiz(request, cookie, session);


        let rid = cookie.get("rid");
        if(rid && 0 < rid){
            do_content_house_rent_modify(request, response, cookie, session, resource, UserBiz);
        }else{
            do_content_house_rent_add(request, response, cookie, session, resource, UserBiz).then(function(){
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

async function do_content_house_rent_add(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_house_rent_add");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200House();
  
        house.user_id = session.get("userid");
        house.city_id = session.get("cityid");
        house.title = request.get("title");
        house.content = request.get("content");
        
        if(T200HttpsForm.verify_id(house.user_id)
            && T200HttpsForm.verify_id(house.city_id)
            && T200HttpsForm.verify_text(house.title)
            && T200HttpsForm.verify_text(house.content)){
                house._table = "house_rent";
                house._fields = house.fields();
                house._values = house.values();
                UserBiz.append(house.merge_insert()).then(resolve, reject);
        }else{
            reject();
        }
    });

    return promise;
}

async function do_content_house_rent_modify(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_house_rent_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}


global.action.use_post('/content/house/rent/edit', do_content_house_rent_edit);
