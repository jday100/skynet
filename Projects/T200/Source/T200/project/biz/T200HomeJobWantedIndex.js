const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeUserBiz = require('./T200HomeUserBiz.js');
const T200UserJobWanted = require('../models/T200UserJobWanted.js');


class T200HomeJobWantedIndex extends T200HomeUserBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    load_index() {
        log(__filename, "load");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let data = {};

            self.load_wanted_full(data).then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.load_wanted_part(data);
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

    

    load_wanted_full(data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let job = new T200UserJobWanted();
            job._fields = job.list_fields();
            job._order_direction = "DESC";
            return self.list(job.merge_list()).then(function(values){
                data.wanted_fulls = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_wanted_part(data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let job = new T200UserJobWanted();
            job._fields = job.list_fields();
            job._order_direction = "DESC";
            return self.list(job.merge_list()).then(function(values){
                data.wanted_parts = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200HomeJobWantedIndex;