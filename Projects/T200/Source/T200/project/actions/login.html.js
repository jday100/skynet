const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HttpsForm = require('../../library/net/T200HttpsForm.js');
const T200Visitor = require('../models/T200Visitor.js');
const T200HomeVisitorBiz = require('../biz/T200HomeVisitorBiz.js');
const T200HomeUserBiz = require('../biz/T200HomeUserBiz.js');


async function do_login(request, response, cookie, session, resource) {
    log(__filename, "do_login");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let visitor = new T200Visitor();
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

        visitor.username = request.get('username');
        visitor.password = request.get('password');

        if(T200HttpsForm.verify_text(visitor.username)
            && T200HttpsForm.verify_text(visitor.password)){

            VisitorBiz.login(visitor).then(function(data){
                set_data(cookie, session, data);

                response.type('json');
                response.data('success');
                resolve();
            }, function(err){
                response.type('json');
                response.data('failure');
                reject(err);
            }).catch(function(err){
                response.type('json');
                reject();
            });

        }else{
            response.type('json');
            reject(T200Error.build(1));
        }
    });

    return promise;
}

function set_data(cookie, session, data) {
    let sid = session.build_sid(data);

    cookie.set('sid', sid);

    let result = {};

    result.userid = data.user_id;
    result.cityid = data.city_id;
    result.username = data.username;
    result.password = data.password;

    session.key(sid, result);
}


async function do_content_person_region(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_region");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let city_id = session.get("cityid");

        if(T200HttpsForm.verify_id(city_id)){
            response.type("json");
            response.success(city_id);
            resolve(city_id);
        }else{
            response.type("json");
            reject();
        }
    
    });

    return promise;
}


global.action.use_post('/login', do_login);
global.action.use_post('/content/person/region', do_content_person_region);