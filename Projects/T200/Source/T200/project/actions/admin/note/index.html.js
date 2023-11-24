const { error, log } = require('../../../../library/T200Lib.js');
const T200Error = require('../../../../library/T200Error.js');

const T200HttpsForm = require('../../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../../view/T200HomeView.js');
const T200Note = require('../../../models/T200Note.js');
const T200HomeAdminBiz = require('../../../biz/T200HomeAdminBiz.js');


async function do_admin_note_list(request, response, cookie, session, resource) {
    log(__filename, "do_admin_note_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200Note();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        note._fields = note.list_fields();
        note._order_direction = "DESC";
        AdminBiz.paging(note).then(function(result){
            let view = new T200HomeView(resource);
            let data = {};
            data.paging = result.paging;
            data.notes = result.values;
            return view.render_file("admin/note/index.ejs", data).then(function (value) {
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

    });

    return promise;
}

async function do_admin_note_search(request, response, cookie, session, resource) {
    log(__filename, "do_admin_note_search");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let note = new T200Note();
        let AdminBiz = new T200HomeAdminBiz(request, cookie, session);

        if(true){
            note._fields = note.fulltext_result_fields();
            note._search_fields = note.fulltext_fields();
            note._order_direction = "DESC";
            AdminBiz.fulltext(note).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.notes = result.values;
                return view.render_file("admin/note/index.ejs", data).then(function (value) {
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


global.action.use_post('/admin/note/list', do_admin_note_list);
global.action.use_post('/admin/note/search', do_admin_note_search);