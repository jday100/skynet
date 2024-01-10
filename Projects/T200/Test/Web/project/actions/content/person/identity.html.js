const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200Dotter = require('../../../../library/T200Dotter.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserPerson = require('../../../models/T200UserPerson.js');
const T200UserNickname = require('../../../models/T200UserNickname.js');

const T200UserIdentity = require('../../../models/T200UserIdentity.js');

const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');


async function do_content_person_identity(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_identity");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let identity = new T200UserIdentity();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let username = session.get("username");

        identity.user_id = session.get("userid");
        identity.identity_id = session.get("identityid");

        if(T200HttpsForm.verify_id(identity.user_id)
            && T200HttpsForm.verify_id(identity.identity_id)){
            identity.flash_content_identity_fields();
            UserBiz.load(identity.merge_select_by_key()).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                if(result){
                    data.identity = result;
                }else{
                    data.identity = {};
                }
                data.identity.username = username;
                return view.render_file("content/person/identity.ejs", data).then(function (value) {
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

function do_content_person_nickname_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_nickname_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let nickname = new T200UserNickname();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let user_id = session.get("userid");
        let pwd1 = request.get("password");
        let pwd2 = session.get("password");
        nickname.nickname = request.get("nickname");

        if(T200HttpsForm.verify_text(pwd1)
                && T200HttpsForm.verify_text(pwd2)
                && T200HttpsForm.verify_id(user_id)
                && pwd1 == pwd2
                && T200HttpsForm.verify_text(nickname.nickname)){
                    nickname.flash_content_search_fields();
                    return UserBiz.search(nickname.merge_content_status_search()).then(function(data){
                        if(data && 0 == data.length){
                            nickname.user_id = user_id;
                            nickname.status = 1;
                            nickname.flash_content_append_fields();
                            nickname.flash_content_append_values();
                            return UserBiz.append(nickname.merge_user_insert()).then(function(result){
                                let id = result;
    
                                if(T200HttpsForm.verify_id(id)){
                                    let person = new T200UserPerson();
    
                                    person.user_id = user_id;
                                    person.nickname_id = id;
                                    person.nickname = nickname.nickname;
                                    person.flash_content_nickname_update();
                                    return UserBiz.modify(person.merge_update_by_key()).then(function(){
                                        response.type("json");
                                        resolve();
                                    }, function(){
                                        response.type("json");
                                        reject();
                                    })
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


async function do_content_person_identity_location_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_identity_location_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let identity = new T200UserIdentity();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        identity.user_id = session.get("userid");
        identity.continent_id = request.get("continent");
        identity.region_id = request.get("region");
        identity.city_id = request.get("city");

        if(T200HttpsForm.verify_id(identity.user_id)
            && T200HttpsForm.verify_id(identity.continent_id)
            && T200HttpsForm.verify_id(identity.region_id)
            && T200HttpsForm.verify_id(identity.city_id)){
            identity.flash_content_identity_location_update();
            UserBiz.modify(identity.merge_update_by_id()).then(function(result){
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
  
    });

    return promise;
}


async function do_content_person_identity_intro_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_identity_intro_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let identity = new T200UserIdentity();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        identity.user_id = session.get("userid");
        identity.intro = request.get("intro");

        if(T200HttpsForm.verify_id(identity.user_id)
            && T200HttpsForm.verify_text(identity.intro)){
            identity.flash_content_identity_intro_update();
            UserBiz.modify(identity.merge_update_by_id()).then(function(result){
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
  
    });

    return promise;
}



global.action.use_post('/content/person/identity', do_content_person_identity);

global.action.use_post('/content/person/nickname/save', do_content_person_nickname_save);


global.action.use_post('/content/person/identity/location/save', do_content_person_identity_location_save);
global.action.use_post('/content/person/identity/intro/save', do_content_person_identity_intro_save);
