const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeUserBiz = require('./T200HomeUserBiz.js');
const T200UserHouseWanted = require('../models/T200UserHouseWanted.js');


class T200HomeHouseWantedIndex extends T200HomeUserBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    load_index(id) {
        log(__filename, "load");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let data = {};

            self.load_wanted_long(id, data).then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.load_wanted_short(id, data);
            }, function(){
                return error();
            }).then(function(){
                resolve(data);
            }, function(){
                reject();
            });

        });

        return promise;
    }

    

    load_wanted_long(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let house = new T200UserHouseWanted();
            house.city_id = id;
            house._fields = house.list_fields();
            return self.list(house.merge_user_paging_city_long_list()).then(function(values){
                data.house_longs = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_wanted_short(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let house = new T200UserHouseWanted();
            house.city_id = id;
            house._fields = house.list_fields();
            return self.list(house.merge_user_paging_city_short_list()).then(function(values){
                data.house_shorts = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200HomeHouseWantedIndex;