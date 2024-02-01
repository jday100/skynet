const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Crypto = require('../../library/crypto/T200Crypto.js');
const T200HttpsForm = require('../../library/net/T200HttpsForm.js');

const T200Visitor = require('../models/T200Visitor.js');
const T200Invitation = require('../models/T200Invitation.js');
const T200HomeVisitorBiz = require('../biz/T200HomeVisitorBiz.js');

async function do_register(request, response, cookie, session, resource) {
    log(__filename, "do_register");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        if(global.setup.server){
            if(global.setup.server.register){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }

        let visitor = new T200Visitor();
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

        let username = request.get("username");
        let pwd1 = request.get("password1");
        let pwd2 = request.get("password2");
        let email = request.get("email");
        let auth = request.get("authcode");
        let invite = request.get("invitecode");

        if(T200HttpsForm.verify_texts(2, 50, username)
            && T200HttpsForm.verify_texts(6, 50, pwd1)
            && T200HttpsForm.verify_texts(6, 50, pwd2)
            && T200HttpsForm.verify_email(email)
            && T200HttpsForm.verify_texts_6(auth)
            && T200HttpsForm.verify_texts_12(invite)
            && pwd1 == pwd2){

            let invitation = new T200Invitation();

            invitation.invite = invite;
            invitation.flash_invitation_fields();
            VisitorBiz.load(invitation.merge_select_by_field("invite")).then(function(){
                visitor.username = username;
                visitor.password = T200Crypto.sha1(pwd1);
                visitor.email = email;
                visitor.invite = invite;
                VisitorBiz.register(visitor).then(function(){
                    response.type('json');
                    resolve();
                }, function(){
                    response.type('json');
                    reject();
                });
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

async function do_register_verify(request, response, cookie, session, resource) {
    log(__filename, "do_register_verify");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let visitor = new T200Visitor();
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

        let result = new Array();

        let username = request.get("username");
        let pwd1 = request.get("password1");
        let pwd2 = request.get("password2");
        let email = request.get("email");
        let auth = request.get("authcode");
        let invite = request.get("invitecode");

        if(T200HttpsForm.verify_texts(2, 50, username)){
            
        }else{
            result.push(1);
        }

        if(T200HttpsForm.verify_texts(6, 50, pwd1)){
            
        }else{
            result.push(2);
        }

        if(T200HttpsForm.verify_texts(6, 50, pwd2)){

        }else{
            result.push(3);
        }

        if(pwd1 == pwd2){

        }else{
            result.push(10);
        }

        if(T200HttpsForm.verify_email(email)){

        }else{
            result.push(4);
        }

        if(T200HttpsForm.verify_texts_6(auth)){

        }else{
            result.push(5);
        }

        if(T200HttpsForm.verify_texts_12(invite)){

        }else{
            result.push(6);
        }

        if(0 == result.length){
            visitor.username = username;
            visitor.flash_visitor_fields();
            return VisitorBiz.load(visitor.merge_select_by_field('username')).then(function(){
                result.push(1);
            }, function(){

            }).finally(function(){
                visitor.email = email;
                visitor.flash_visitor_fields();
                return VisitorBiz.load(visitor.merge_select_by_field('email')).then(function(){
                    result.push(4);
                }, function(){

                });
            }).finally(function(){
                let invitation = new T200Invitation();

                invitation.invite = invite;
                invitation.flash_invitation_fields();
                return VisitorBiz.load(invitation.merge_select_by_field('invite')).then(function(){

                }, function(){
                    result.push(6);
                });
            }).finally(function(){
                response.type("json");
                resolve(result);
            });
        }else{
            response.type("json");
            resolve(result);
        }

    });

    return promise;
}


global.action.use_post('/register', do_register);
global.action.use_post('/register/verify', do_register_verify);