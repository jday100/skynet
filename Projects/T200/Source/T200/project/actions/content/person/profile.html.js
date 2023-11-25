const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200Person = require('../../../models/T200Person.js');
const T200HomeUserBiz = require('../../../biz/T200HomeUserBiz.js');


async function do_content_person_profile(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_profile");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200Person();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){
            person._fields = person.list_fields();
            UserBiz.get_one(person, user_id).then(function(result){
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


global.action.use_post('/content/person/profile', do_content_person_profile);
