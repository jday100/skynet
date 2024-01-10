const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeUserBiz = require('./T200HomeUserBiz.js');
const T200UserHouseRent = require('../models/T200UserHouseRent.js');


class T200HomeHouseRentIndex extends T200HomeUserBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    load_index(id) {
        log(__filename, "load");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let data = {};

            self.load_rent_long(id, data).then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.load_rent_short(id, data);
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

    

    load_rent_long(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let house = new T200UserHouseRent();
            house.region_id = id;
            house._fields = house.list_fields();
            return self.list(house.merge_user_paging_long_region_list()).then(function(values){
                data.house_longs = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_rent_short(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let house = new T200UserHouseRent();
            house.region_id = id;
            house._fields = house.list_fields();
            return self.list(house.merge_user_paging_short_region_list()).then(function(values){
                data.house_shorts = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200HomeHouseRentIndex;