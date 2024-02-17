const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200Notice = require('../../models/T200Notice.js');
const T200HomeVisitorBiz = require('../../biz/T200HomeVisitorBiz.js');


async function do_notice_list(request, response, cookie, session, resource) {
    log(__filename, "do_notice_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        if(global.setup.server){
            if(global.setup.server.list){

            }else{
                response.type('json');
                reject('Close');
                return;
            }
        }

        let notice = new T200Notice();
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

        if(true){
            notice._fields = notice.list_fields();
            notice._order_direction = "desc";
            notice.merge_paging_count = notice.merge_count;
            notice.merge_paging_list = notice.merge_paging;
            VisitorBiz.paging2(notice).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.notices = result.values;
                data.search = "";
                return view.render_file("notice/index.ejs", data).then(function (value) {
                    response.type("json");
                    resolve(value);
                }, function (err) {
                    response.type("json");
                    reject();
                });
            }, function (err) {
                response.type("json");
                reject();
            });

        }else{
            reject(T200Error.build(1));
        }
    });

    return promise;
}

async function do_notice_search(request, response, cookie, session, resource) {
    log(__filename, "do_notice_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200Notice();
        let VisitorBiz = new T200HomeVisitorBiz(request, cookie, session);

        let search = request.get("search");

        if(T200HttpsForm.verify_text(search)){
            notice._search = search;
            notice.flash_paging_fields();
            notice.flash_fulltext_fields();
            notice.merge_fulltext_count = notice.merge_fulltext_count;
            notice.merge_fulltext_list = notice.merge_fulltext_list;
            VisitorBiz.fulltext2(notice).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.notices = result.values;
                data.search = notice._search;
                return view.render_file("notice/index.ejs", data).then(function (value) {
                    response.type("json");
                    resolve(value);
                }, function (err) {
                    response.type("json");
                    reject();
                });
            }, function (err) {
                response.type("json");
                reject();
            });
        }else{
            response.type("json");
            reject();
        }
    });

    return promise;
}


global.action.use_post('/notice/list', do_notice_list);
global.action.use_post('/notice/search', do_notice_search);