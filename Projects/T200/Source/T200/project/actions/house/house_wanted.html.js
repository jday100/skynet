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


global.action.use_post('/house/wanted/board', do_house_wanted_board);