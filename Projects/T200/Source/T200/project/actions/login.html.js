const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Crypto = require('../../library/crypto/T200Crypto.js');
const T200HttpsForm = require('../../library/net/T200HttpsForm.js');

const T200Visitor = require('../models/T200Visitor.js');
const T200UserPerson = require('../models/T200UserPerson.js');
const T200HomeVisitorBiz = require('../biz/T200HomeVisitorBiz.js');
const T200HomeUserBiz = require('../biz/T200HomeUserBiz.js');
const T200CookieItem = require('../../library/net/T200CookieItem.js');


async function do_login(request, response, cookie, session, resource) {
    log(__filename, "do_login");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let visitor = new T200Visitor();
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

        visitor.username = request.get("username");
        let password = request.get("password");

        if(T200HttpsForm.verify_texts(2, 50, visitor.username)
            && T200HttpsForm.verify_texts(6, 50, password)){
            visitor.password = T200Crypto.sha1(password);
            visitor.ip = request.req.ip;
            VisitorBiz.login(visitor).then(function(data){
                set_data(cookie, session, data);

                response.type('json');

                let result = 0;

                if(T200HttpsForm.verify_id(data.flag)){
                    if(T200HttpsForm.verify_id(data.identity_id)){
                        result = 1;
                    }else{
                        result = 3;
                    }
                }else{
                    result = 2;
                }
                resolve(result);
            }, function(){
                response.type('json');
                reject();
            });
        }else{
            response.type('json');
            reject();
        }
    });

    return promise;
}

function set_data(cookie, session, data) {
    let sid = session.build_sid(data);

    cookie.set('sid', sid);

    let result = {};

    result.userid = data.user_id;
    result.continentid = data.continent_id;
    result.continent = data.continent_name;
    result.regionid = data.region_id;
    result.region = data.region_name;
    result.cityid = data.city_id;
    result.city = data.city_name;
    result.identityid = data.identity_id;
    result.status = data.status;
    result.username = data.username;
    result.password = data.password;
    result.flag = data.flag;

    session.key(sid, result);
}



async function do_logout(request, response, cookie, session, resource) {
    log(__filename, "do_logout");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200UserPerson();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        person.user_id = session.get("userid");
        if(T200HttpsForm.verify_id(person.user_id)){
            UserBiz.logout(person).then(function(){
                clear_data(cookie, session, person);

                response.type('json');
                resolve();
            }, function(){
                response.type('json');
                reject();
            });
        }else{
            response.type('json');
            reject();
        }
        
    });

    return promise;
}


function clear_data(cookie, session, person) {
    let item = new T200CookieItem("sid", "0");
    item._path = "/";
    cookie.set_item(item);
}


async function do_content_person_region(request, response, cookie, session, resource) {
    log(__filename, "do_content_person_region");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let continent_id = session.get("continentid");
        let region_id = session.get("regionid");
        let city_id = session.get("cityid");

        if(T200HttpsForm.verify_id(continent_id)
            && T200HttpsForm.verify_id(region_id)
            && T200HttpsForm.verify_id(city_id)){
            
            let data = {};

            data.continent_id = continent_id;
            data.region_id = region_id;
            data.city_id = city_id;

            response.type("json");
            response.success(data);
            resolve(data);
        }else{
            response.type("json");
            reject();
        }
    
    });

    return promise;
}


global.action.use_post('/login', do_login);
global.action.use_post('/logout', do_logout);
global.action.use_post('/content/person/region', do_content_person_region);