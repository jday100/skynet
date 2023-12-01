const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeUserBiz = require('./T200HomeUserBiz.js');
const T200UserHouseWanted = require('../models/T200UserHouseWanted.js');


class T200HomeHouseWantedIndex extends T200HomeUserBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    load_index() {
        log(__filename, "load");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let data = {};

            self.load_wanted_long(data).then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.load_wanted_short(data);
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

    

    load_wanted_long(data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let house = new T200UserHouseWanted();
            house._fields = house.list_fields();
            house._order_direction = "DESC";
            return self.list(house.merge_list()).then(function(values){
                data.house_rents = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_wanted_short(data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let house = new T200UserHouseWanted();
            house._fields = house.list_fields();
            house._order_direction = "DESC";
            return self.list(house.merge_list()).then(function(values){
                data.house_wanteds = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200HomeHouseWantedIndex;