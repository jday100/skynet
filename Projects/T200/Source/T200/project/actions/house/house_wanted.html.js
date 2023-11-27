const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');
const T200UserHouse = require('../../models/T200UserHouse.js');
const T200HomeUserBiz = require('../../biz/T200HomeUserBiz.js');


async function do_house_wanted_list(request, response, cookie, session, resource) {
    log(__filename, "do_house_wanted_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let house = new T200UserHouse();
        let UserBiz = new T200HomeUserBiz(request, cookie, session);

        let item = cookie.get("id");

        if(undefined == item){

        }else{
            house.id = item._value;
        }
        if(T200HttpsForm.verify_id(house.id)){
            house._table = "house_wanted";
            house._fields = house.board_fields();
            house._order_direction = "DESC";
            house.board_count_sql = house.merge_board_count(house.id);
            house.board_list_sql = house.merge_board_list(house.id);
            UserBiz.board(house).then(function(result){
                let view = new T200HomeView(resource);
                let data = {};
                data.paging = result.paging;
                data.houses = result.values;
                return view.render_file("house/wanted.ejs", data).then(function (value) {
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
            reject();
        }
  
    });

    return promise;
}


global.action.use_post('/house/wanted/list', do_house_wanted_list);