const { error, log } = require('../../../library/T200Lib.js');
const T200Error = require('../../../library/T200Error.js');

const T200HttpsForm = require('../../../library/net/T200HttpsForm.js');
const T200HomeView = require('../../view/T200HomeView.js');

const T200HomeTradingRegionIndex = require('../../biz/T200HomeTradingRegionIndex.js');


async function do_trading_region_list(request, response, cookie, session, resource) {
    log(__filename, "do_trading_region_list");
    let self = this;
    let promise = new Promise(function(resolve, reject){
        let view = new T200HomeView(resource);
        let TradingIndex = new T200HomeTradingRegionIndex(request, cookie, session);

        let region_id = request.get("id");

        if(T200HttpsForm.verify_id(region_id)){
            return TradingIndex.load_index().then(function(data){
                data.region_id = region_id;
                return view.render_file('trading/index_region.ejs', data);
            }, function(err){
                return error();
            }).then(function(result){
                response.type("json");
                response.success(result);
                resolve(result);
            }, function(err){
                response.type("json");
                reject(err);
                return error();
            });
        }else{
            response.type("json");
            reject(err);
        }
    });

    return promise;
}


global.action.use_post('/trading/region/list', do_trading_region_list);