const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200Crypto = require('../../library/crypto/T200Crypto.js');
const T200HttpsForm = require('../../library/net/T200HttpsForm.js');



async function do_form(request, response, cookie, session, resource) {
    log(__filename, "do_form");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        resolve();
    });

    return promise;
}



global.action.use_post('/form', do_form);