const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200Visitor = require('../../models/T200Visitor.js');
const T200HomeVisitorBiz = require('../../biz/T200HomeVisitorBiz.js');


async function do_admin_login(request, response, cookie, session, resource) {
    log(__filename, "do_admin_login");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let visitor = new T200Visitor();
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

        visitor.username = request.get('username');
        visitor.password = request.get('password');

        if(T200HttpsForm.verify_text(visitor.username)
            && T200HttpsForm.verify_text(visitor.password)){

            VisitorBiz.admin_login(visitor).then(function(data){
                set_data(cookie, session, data);

                response.type('json');
                response.data('success');
                resolve();
            }, function(err){
                response.type('json');
                response.data('failure');
                reject(err);
            }).catch(function(err){
                console.log(err);
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

    let result = {};

    result.userid = data[0].user_id;
    result.username = data[0].username;

    session.set(sid, result);
}

global.action.use_post('/admin/login', do_admin_login);