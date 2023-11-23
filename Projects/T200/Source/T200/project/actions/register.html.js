const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HttpsForm = require('../../library/net/T200HttpsForm.js');
const T200Visitor = require('../models/T200Visitor.js');
const T200HomeVisitorBiz = require('../biz/T200HomeVisitorBiz.js');


async function do_register(request, response, cookie, session, resource) {
    log(__filename, "do_register");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let visitor = new T200Visitor();
        let VisitorBiz = new T200HomeVisitorBiz();

        let pwd1 = request.get("password1");
        let pwd2 = request.get("password2");
        let auth = request.get("authcode");
        let invite = request.get("invitecode");

        if(pwd1 == pwd2){
            visitor.password = pwd1;
        }

        visitor.username = request.get('username');
        visitor.email= request.get("email");

        if(T200HttpsForm.verify_text(visitor.username)
            && T200HttpsForm.verify_text(visitor.password)
            && T200HttpsForm.verify_email(visitor.email)){

            visitor._fields = visitor.fields();
            visitor._values = visitor.values();
            VisitorBiz.register(visitor).then(function(data){
                response.type('json');
                response.data('success');
                resolve();
            }, function(err){
                response.type('json');
                response.data('failure');
                reject(err);
            }).catch(function(err){
                console.log(err);
                reject(err);
            });

        }else{
            reject(T200Error.build(1));
        }
    });

    return promise;
}


global.action.use_post('/register', do_register);