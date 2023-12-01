const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeUserBiz = require('./T200HomeUserBiz.js');
const T200House = require('../models/T200House.js');


class T200HomeHouseRentIndex extends T200HomeUserBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    load_index() {
        log(__filename, "load");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let data = {};

            self.load_rent_long(data).then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.load_rent_short(data);
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

    

    load_rent_long(data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let house = new T200House();
            house._table = "house_rent";
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

    load_rent_short(data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let house = new T200House();
            house._table = "house_rent";
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

module.exports = T200HomeHouseRentIndex;