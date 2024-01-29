const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Crypto = require('../../library/crypto/T200Crypto.js');
const T200HttpsForm = require('../../library/net/T200HttpsForm.js');
const T200HomeView = require('../view/T200HomeView.js');
const T200HomeIndex = require('../biz/T200HomeIndex.js');

async function do_index(request, response, cookie, session, resource) {
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let view = new T200HomeView(resource);
        let HomeIndex = new T200HomeIndex(request, cookie, session);

        let logined = false;
        let user_id = session.get("userid");

        if(T200HttpsForm.verify_id(user_id)){
            logined = true;
        }

        return HomeIndex.load_index().then(function(data){
            data.logined = logined;
            return view.render_file('index.ejs', data);
        }, function(err){
            return error();
        }).then(function(result){
            response.success(result);
            resolve(result);
        }, function(err){
            reject(err);
            return error();
        });

    });

    return promise;
}

async function do_datum(request, response, cookie, session, resource) {
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let name = request.get("id");

        let value = T200Crypto.decrypt_aes(name);

        if(T200HttpsForm.verify_text(value)){
            let dir = resource.merge_store();

            if(dir){
                let file = `${dir}/${value}`;

                resource.load_file(file).then(function(data){
                    resolve(data);
                }, function(){
                    reject();
                });
            }else{
                reject();
            }
        }else{
            reject();
        }
    });

    return promise;
}


module.exports = { do_index, do_datum };