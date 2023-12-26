const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserNote = require('../../models/T200UserNote.js');
const T200UserFollow = require('../../models/T200UserFollow.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');

async function do_oct_server(request, response, cookie, session, resource) {
    log(__filename, "do_oct_server");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        
    });

    return promise;
}

async function do_oct_list(request, response, cookie, session, resource) {
    log(__filename, "do_oct_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        
    });

    return promise;
}

async function do_oct_send(request, response, cookie, session, resource) {
    log(__filename, "do_oct_send");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        
    });

    return promise;
}


async function do_content_person_follow(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_follow");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let follow = new T200UserFollow();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let user_id = session.get("userid");
        follow.identity_id = request.get("id");

        if(T200HttpsForm.verify_id(user_id)
            && T200HttpsForm.verify_id(follow.identity_id)){
            follow.user_id = user_id;
            follow.flash_content_append_fields();
            follow.flash_content_append_values();
            UserBiz.append(follow.merge_user_insert()).then(function(){
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


global.action.use_socket('/oct/server', do_oct_server);
global.action.use_post('/oct/list', do_oct_list);
global.action.use_post('/oct/send', do_oct_send);
global.action.use_post('/content/person/follow', do_content_person_follow);
