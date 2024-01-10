const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserHouseWanted = require('../../models/T200UserHouseWanted.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_house_wanted_board(request, response, cookie, session, resource) {
    log(__filename, "do_house_wanted_board");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let item = cookie.get("id");

        if(undefined == item){

        }else{
            house.id = item._value;
        }

        if(T200HttpsForm.verify_id(house.id)){
            house.flash_user_board_fields();
            house.merge_board_count = house.merge_user_board_count;
            house.merge_board_list = house.merge_user_board_list;
            UserBiz.board(house).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.houses = result.values;
                return view.render_file("house/house_wanted.ejs", data).then(function (value) {
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


async function do_house_wanted_reply(request, response, cookie, session, resource) {
    log(__filename, "do_house_wanted_reply");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouseWanted();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let nickname = request.get("nickname");

        house.user_id = session.get("userid");
        house.identity_id = session.get("identityid");
        house.city_id = session.get("cityid");
        house.parent_id = request.get("parentid");
        house.title = `@${nickname}`;
        house.content = request.get("content");
        house.status = 1;

        if(T200HttpsForm.verify_id(house.user_id)
            && T200HttpsForm.verify_id(house.identity_id)
            && T200HttpsForm.verify_id(house.city_id)
            && T200HttpsForm.verify_id(house.parent_id)
            && T200HttpsForm.verify_id(house.status)
            && T200HttpsForm.verify_text(nickname)
            && T200HttpsForm.verify_text(house.content)){
            house.flash_reply_fields();
            house.flash_reply_values();
            UserBiz.append(house.merge_user_insert()).then(function(){
                do_house_wanted_board_panel(house, UserBiz, cookie, resource).then(function(result){
                    response.type("json");
                    resolve(result);
                }, function(){
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


function do_house_wanted_board_panel(house, UserBiz, cookie, resource) {
    log(__filename, "do_house_wanted_board_panel");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let item = cookie.get("id");

        if(undefined == item){

        }else{
            house.id = item._value;
        }

        if(T200HttpsForm.verify_id(house.id)){
            house.flash_user_board_fields();
            house.merge_board_count = house.merge_user_board_count;
            house.merge_board_list = house.merge_user_board_list;
            UserBiz.board(house).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.houses = result.values;
                return view.render_file("house/house_wanted.ejs", data).then(function (value) {
                    resolve(value);
                }, function (err) {
                    reject();
                });
            }, function (err) {
                reject();
            });
        }else{
            reject();
        }
  
    });

    return promise;
}


global.action.use_post('/house/wanted/board', do_house_wanted_board);
global.action.use_post('/house/wanted/reply', do_house_wanted_reply);