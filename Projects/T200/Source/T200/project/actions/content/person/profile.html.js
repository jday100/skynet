const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserPerson = require('../../../models/T200UserPerson.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');


async function do_content_person_profile(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_profile");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200UserPerson();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        person.user_id = session.get("userid");

        if(T200HttpsForm.verify_id(person.user_id)){
            person._fields = person.profile_fields();
            UserBiz.load(person.merge_select_by_key()).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.profile = result;
                return view.render_file("content/person/profile.ejs", data).then(function (value) {
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

async function do_content_person_nickname_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_nickname_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200UserPerson();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        person.user_id = session.get("userid");
        person.password = request.get("password");
        person.nickname = request.get("nickname");

        if(T200HttpsForm.verify_id(person.user_id)
            && T200HttpsForm.verify_text(person.password)
            && T200HttpsForm.verify_text(person.nickname)){

            let password = session.get("password");

            if(undefined == password
                || password != person.password){
                    
                response.type("json");
                reject();
            }else{
                delete person.password;
                person._name_value = person.modify_nickname_array();
                UserBiz.modify(person.merge_update_by_key()).then(function(result){
                    response.type("json");
                    if(result){
                        resolve();
                    }else{
                        reject();
                    }
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


async function do_content_person_password_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_password_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200UserPerson();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let opwd = request.get('opwd');
        let pwd1 = request.get('pwd1');
        let pwd2 = request.get('pwd2');

        let pwd = session.get('password');

        person.user_id = session.get("userid");

        if(T200HttpsForm.verify_text(opwd)
            && T200HttpsForm.verify_text(pwd1)
            && T200HttpsForm.verify_text(pwd2)
            && T200HttpsForm.verify_text(pwd)
            && T200HttpsForm.verify_text(person.user_id)){

            if(pwd1 == pwd2 && opwd == pwd){
                person.password = pwd1;
                person._name_value = person.modify_password_array();
                UserBiz.modify(person.merge_update_by_key()).then(function(result){
                    session.set('password', pwd1);
                    response.type("json");
                    if(result){
                        resolve();
                    }else{
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
        }else{
            response.type("json");
            reject();
        }
  
    });

    return promise;
}



async function do_content_person_email_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_email_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200Person();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        person.user_id = session.get("userid");
        person.city_id = request.get("city");

        if(T200HttpsForm.verify_id(person.user_id)
            && T200HttpsForm.verify_id(person.city_id)){
            UserBiz.modify(person.merge_city_update()).then(function(result){
                response.type("json");
                if(result){
                    resolve();
                }else{
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



async function do_content_person_nationality_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_nationality_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200Person();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        person.user_id = session.get("userid");
        person.city_id = request.get("city");

        if(T200HttpsForm.verify_id(person.user_id)
            && T200HttpsForm.verify_id(person.city_id)){
            UserBiz.modify(person.merge_city_update()).then(function(result){
                response.type("json");
                if(result){
                    resolve();
                }else{
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


async function do_content_person_location_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_location_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200Person();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        person.user_id = session.get("userid");
        person.city_id = request.get("city");

        if(T200HttpsForm.verify_id(person.user_id)
            && T200HttpsForm.verify_id(person.city_id)){
            UserBiz.modify(person.merge_city_update()).then(function(result){
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


async function do_content_person_intro_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_intro_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200Person();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        person.user_id = session.get("userid");
        person.city_id = request.get("city");

        if(T200HttpsForm.verify_id(person.user_id)
            && T200HttpsForm.verify_id(person.city_id)){
            UserBiz.modify(person.merge_city_update()).then(function(result){
                response.type("json");
                if(result){
                    resolve();
                }else{
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



global.action.use_post('/content/person/profile', do_content_person_profile);

global.action.use_post('/content/person/nickname/save', do_content_person_nickname_save);
global.action.use_post('/content/person/password/save', do_content_person_password_save);
global.action.use_post('/content/person/email/save', do_content_person_email_save);

global.action.use_post('/content/person/nationality/save', do_content_person_nationality_save);
global.action.use_post('/content/person/location/save', do_content_person_location_save);
global.action.use_post('/content/person/intro/save', do_content_person_intro_save);
