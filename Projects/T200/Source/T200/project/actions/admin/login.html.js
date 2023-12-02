const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200CookieItem = require('../../../library/net/T200CookieItem.js');

const T200VisitorPerson = require('../../models/T200VisitorPerson.js');
const T200HomeVisitorBiz = require('../../biz/T200HomeVisitorBiz.js');


async function do_admin_login(request, response, cookie, session, resource) {
    log(__filename, "do_admin_login");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let person = new T200VisitorPerson();
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

        person.username = request.get('username');
        person.password = request.get('password');

        if(T200HttpsForm.verify_text(person.username)
            && T200HttpsForm.verify_text(person.password)){

            VisitorBiz.admin_login(person).then(function(data){
                set_data(cookie, session, data);

                response.type('json');
                response.data('success');
                resolve();
            }, function(err){
                response.type('json');
                response.data('failure');
                reject(err);
            }).catch(function(err){
                reject();
            });

        }else{
            reject(T200Error.build(1));
        }
    });

    return promise;
}

function set_data(cookie, session, data) {
    let sid = session.build_sid(data);

    cookie.set('sid', sid);


    let item = new T200CookieItem('sid', sid);

    item._path = "/admin/";
    
    cookie.set_item(item);


    let result = {};

    result.userid = data.user_id;
    result.username = data.username;

    session.key(sid, result);
}

global.action.use_post('/admin/login', do_admin_login);