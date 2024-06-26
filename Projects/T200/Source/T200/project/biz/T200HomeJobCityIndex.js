const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeUserBiz = require('./T200HomeUserBiz.js');
const T200UserJobRecruit = require('../models/T200UserJobRecruit.js');
const T200UserJobWanted = require('../models/T200UserJobWanted.js');


class T200HomeJobIndex extends T200HomeUserBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    load_index(id) {
        log(__filename, "load");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let data = {};

            self.load_recruit_full(id, data).then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.load_recruit_part(id, data);
            }, function(){
                return error();
            }).then(function(){
                return self.load_wanted_full(id, data);
            }, function(){
                return error();
            }).then(function(){
                return self.load_wanted_part(id, data);
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

    

    load_recruit_full(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let job = new T200UserJobRecruit();
            job.city_id = id;
            job._type = "type_full";
            job._fields = job.list_fields();
            return self.list(job.merge_user_paging_city_type_list()).then(function(values){
                data.recruit_fulls = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_recruit_part(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let job = new T200UserJobRecruit();
            job.city_id = id;
            job._type = "type_part";
            job._fields = job.list_fields();
            return self.list(job.merge_user_paging_city_type_list()).then(function(values){
                data.recruit_parts = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_wanted_full(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let job = new T200UserJobWanted();
            job.city_id = id;
            job._type = "type_full";
            job._fields = job.list_fields();
            return self.list(job.merge_user_paging_city_type_list()).then(function(values){
                data.wanted_fulls = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_wanted_part(id, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let job = new T200UserJobWanted();
            job.city_id = id;
            job._type = "type_part";
            job._fields = job.list_fields();
            return self.list(job.merge_user_paging_city_type_list()).then(function(values){
                data.wanted_parts = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200HomeJobIndex;