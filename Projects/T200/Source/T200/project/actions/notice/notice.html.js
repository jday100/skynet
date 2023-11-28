const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200Notice = require('../../models/T200Notice.js');
const T200HomeVisitorBiz = require('../../biz/T200HomeVisitorBiz.js');


async function do_notice_get(request, response, cookie, session, resource) {
    log(__filename, "do_notice_get");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200Notice();
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

        let item = cookie.get("nid");

        if(undefined == item){

        }else{
            notice.id = item._value;
        }

        if(T200HttpsForm.verify_id(notice.id)){
            notice._fields = notice.view_fields();
            VisitorBiz.load(notice.merge_select_by_key(notice.id)).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                if(result && 1 == result.length){
                    data.notice = result[0];
                    return view.render_file("notice/notice.ejs", data).then(function (value) {
                        response.type("json");
                        resolve(value);
                    }, function (err) {
                        response.type("json");
                        reject();
                    });
                }else{
                    response.type("json");
                    reject();
                }                
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


global.action.use_post('/notice/notice', do_notice_get);