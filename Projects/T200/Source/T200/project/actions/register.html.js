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
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

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

            VisitorBiz.register(visitor).then(function(data){
                response.type('json');
                response.data('success');
                resolve();
            }, function(err){
                response.type('json');
                response.data('failure');
                reject(err);
            }).catch(function(err){
                response.type('json');
                reject(err);
            });

        }else{
            response.type('json');
            reject(T200Error.build(1));
        }
    });

    return promise;
}


async function do_register_verify(request, response, cookie, session, resource) {
    log(__filename, "do_register_verify");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let visitor = new T200Visitor();
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

        let result = new Array();

        let username = request.get("username");
        let email = request.get("email");

        if(T200HttpsForm.verify_text(username)){
            visitor.username = username;
            visitor.flash_visitor_fields();
            VisitorBiz.load(visitor.merge_select_by_field('username')).then(function(){
                result.push(1);
            }, function(){
             
            }).finally(function(){
                if(T200HttpsForm.verify_email(email)){
                    visitor.email = email;
                    visitor.flash_visitor_fields();
                    VisitorBiz.load(visitor.merge_select_by_field('email')).then(function(){
                        result.push(2);
                        response.type("json");
                        resolve(result);
                    }, function(){
                        response.type("json");
                        resolve(result);
                    });
                }else{
                    result.push(2);
                    response.type("json");
                    reject(result);
                }
            });
        }else{
            result.push(1);
            if(T200HttpsForm.verify_email(email)){
                visitor.email = email;
                visitor.flash_visitor_fields();
                VisitorBiz.load(visitor.merge_select_by_field('email')).then(function(){
                    result.push(2);
                    response.type("json");
                    resolve(result);
                }, function(){
                    response.type("json");
                    resolve(result);
                });
            }else{
                result.push(2);
                response.type("json");
                reject(result);
            }
        }
    });

    return promise;
}


global.action.use_post('/register', do_register);
global.action.use_post('/register/verify', do_register_verify);