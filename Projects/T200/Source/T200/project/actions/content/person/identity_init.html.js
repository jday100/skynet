const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200Dotter = require('../../../../library/T200Dotter.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserPerson = require('../../../models/T200UserPerson.js');
const T200UserNickname = require('../../../models/T200UserNickname.js');

const T200UserIdentity = require('../../../models/T200UserIdentity.js');

const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');


async function do_content_person_identity_init(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_identity_init");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let identity = new T200UserIdentity();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let identity_id = session.get("identityid");
        let username = session.get("username");
        identity.user_id = session.get("userid");


        if(T200HttpsForm.verify_id(identity.user_id)
            && T200HttpsForm.verify_zero(identity_id)){
                let view = new T200HomeView(resource);
                let data = {};
                if(0 == identity_id){
                    data.identity = {};
                    data.identity.username = username;
                    return view.render_file("content/person/identity_init.ejs", data).then(function (value) {
                        response.type("json");
                        resolve(value);
                    }, function (err) {
                        response.type("json");
                        reject();
                    });
                }else{
                    identity.identity_id = identity_id;
                    identity.flash_content_identity_fields();
                    UserBiz.load(identity.merge_select_by_id()).then(function(result){
                        data.identity = result;
                        return view.render_file("content/person/identity_init.ejs", data).then(function (value) {
                            response.type("json");
                            resolve(value);
                        }, function (err) {
                            response.type("json");
                            reject();
                        });
                    }, function(){
                        response.type("json");
                        reject();
                    });
                }
        }else{
            response.type("json");
            reject();
        }
    
    });

    return promise;
}


async function do_content_person_identity_init_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_identity_init_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let identity = new T200UserIdentity();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let identity_id = session.get("identityid");
        identity.user_id = session.get("userid");
        identity.nickname = request.get("nickname");
        identity.continent_id = request.get("continent");
        identity.continent_name = request.get("continent_title");
        identity.region_id = request.get("region");
        identity.region_name = request.get("region_title");
        identity.city_id = request.get("city");
        identity.city_name = request.get("city_title");
        identity.intro = request.get("intro");

        if(T200HttpsForm.verify_null(identity_id)
            && T200HttpsForm.verify_id(identity.user_id)
            && T200HttpsForm.verify_text(identity.nickname)
            && T200HttpsForm.verify_id(identity.continent_id)
            && T200HttpsForm.verify_text_100(identity.continent_name)
            && T200HttpsForm.verify_id(identity.region_id)
            && T200HttpsForm.verify_text_100(identity.region_name)
            && T200HttpsForm.verify_id(identity.city_id)
            && T200HttpsForm.verify_text_100(identity.city_name)
            && T200HttpsForm.verify_empty(identity.intro)){

            if(identity_id && 0 < identity_id){
                do_content_person_identity_init_modify(request, response, cookie, session, resource, UserBiz);
            }else{
                do_content_person_identity_init_append(request, response, cookie, session, resource, UserBiz).then(function(){
                    response.type("json");
                    resolve();
                }, function(err){
                    response.type("json");
                    reject();
                });
            }

        }else{
            response.type("json");
            reject();
        }
  
    });

    return promise;
}


async function do_content_person_identity_init_append(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_person_identity_init_append");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let identity = new T200UserIdentity();

        let identity_id = session.get("identityid");
  
        identity.user_id = session.get("userid");
        identity.nickname = request.get("nickname");
        identity.continent_id = request.get("continent");
        identity.continent_name = request.get("continent_title");
        identity.region_id = request.get("region");
        identity.region_name = request.get("region_title");
        identity.city_id = request.get("city");
        identity.city_name = request.get("city_title");
        identity.intro = request.get("intro");
        identity.status = session.get("status");


        if(T200HttpsForm.verify_null(identity_id)
                && T200HttpsForm.verify_id(identity.user_id)
                && T200HttpsForm.verify_id(identity.status)
                && T200HttpsForm.verify_text(identity.nickname)
                && T200HttpsForm.verify_id(identity.continent_id)
                && T200HttpsForm.verify_text_100(identity.continent_name)
                && T200HttpsForm.verify_id(identity.region_id)
                && T200HttpsForm.verify_text_100(identity.region_name)
                && T200HttpsForm.verify_id(identity.city_id)
                && T200HttpsForm.verify_text_100(identity.city_name)
                && T200HttpsForm.verify_empty(identity.intro)){
                identity.flash_content_append_fields();
                identity.flash_content_append_values();
                UserBiz.append(identity.merge_user_insert()).then(function(id){
                    let person = new T200UserPerson();

                    person.user_id = identity.user_id;
                    person.identity_id = id;
                    if(T200HttpsForm.verify_id(person.user_id)
                        && T200HttpsForm.verify_id(person.identity_id)){
                        person.flash_content_profile_identity_update();
                        UserBiz.modify(person.merge_update_by_key()).then(function(){
                            session.set("identityid", person.identity_id);
                            session.set("continentid", identity.continent_id);
                            session.set("continent", identity.continent_name);
                            session.set("regionid", identity.region_id);
                            session.set("region", identity.region_name);
                            session.set("cityid", identity.city_id);
                            session.set("city", identity.city_name);
                            response.type("json");
                            resolve();
                        }, function(){
                            response.type("json");
                            reject();
                        });
                    }else{
                        response.type("json");
                        reject();
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

async function do_content_person_identity_init_modify(request, response, cookie, session, resource, UserBiz) {
    log(__filename, "do_content_person_identity_init_modify");
    let self = this;
    let promise = new Promise(function(resolve, reject){

    });

    return promise;
}



global.action.use_post('/content/person/identity/init', do_content_person_identity_init);
global.action.use_post('/content/person/identity/init/save', do_content_person_identity_init_save);

