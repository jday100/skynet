const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200Notice = require('../../../models/T200Notice.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');


async function do_admin_notice_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_notice_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200Notice();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        if(true){
            notice._fields = notice.list_fields();
            notice._order_direction = "DESC";
            AdminBiz.paging(notice).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.notices = result.values;
                return view.render_file("admin/notice/index.ejs", data).then(function (value) {
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

async function do_admin_notice_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_notice_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let notice = new T200Notice();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        if(true){
            notice._fields = notice.fulltext_result_fields();
            notice._search_fields = notice.fulltext_fields();
            notice._order_direction = "DESC";
            AdminBiz.fulltext(notice).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.notices = result.values;
                return view.render_file("admin/notice/index.ejs", data).then(function (value) {
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


global.action.use_post('/admin/notice/list', do_admin_notice_list);
global.action.use_post('/admin/notice/search', do_admin_notice_search);