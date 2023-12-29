const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200Dotter = require('../../../../library/T200Dotter.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200UserPerson = require('../../../models/T200UserPerson.js');
const T200UserNickname = require('../../../models/T200UserNickname.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');


async function do_content_person_profile_init(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_profile_init");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200UserPerson();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        person.user_id = session.get("userid");
        person.flag = session.get("flag");

        if(T200HttpsForm.verify_zero(person.flag)
            && T200HttpsForm.verify_id(person.user_id)){
            person.flash_profile_fields();
            UserBiz.load(person.merge_select_by_key()).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.profile = result;
                return view.render_file("content/person/profile_init.ejs", data).then(function (value) {
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


async function do_content_person_profile_init_save(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_profile_init_save");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200UserPerson();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let flag = session.get("flag");
        person.user_id = session.get("userid");
        person.continent_id = request.get("continent");
        person.continent_name = request.get("continent_title");
        person.country_id = request.get("country");
        person.country_name = request.get("country_title");
        person.gender = request.get("gender");
        person.year = request.get("year");
        person.month = request.get("month");
        person.day = request.get("day");
        person.intro = request.get("intro");

        if(T200HttpsForm.verify_zero(flag)
            && T200HttpsForm.verify_id(person.user_id)
            && T200HttpsForm.verify_id(person.continent_id)
            && T200HttpsForm.verify_text_100(person.continent_name)
            && T200HttpsForm.verify_id(person.country_id)
            && T200HttpsForm.verify_text_100(person.country_id)
            && T200HttpsForm.verify_null(person.gender)
            && T200HttpsForm.verify_id(person.year)
            && T200HttpsForm.verify_id(person.month)
            && T200HttpsForm.verify_id(person.day)
            && T200HttpsForm.verify_empty(person.intro)){
            person.flash_content_profile_init_update();
            UserBiz.modify(person.merge_update_by_key()).then(function(result){
                response.type("json");
                if(result){
                    session.set('flag', 1);
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



global.action.use_post('/content/person/profile/init', do_content_person_profile_init);
global.action.use_post('/content/person/profile/init/save', do_content_person_profile_init_save);

