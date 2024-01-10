const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200HomeUserBiz = require('./T200HomeUserBiz.js');
const T200UserJobRecruit = require('../models/T200UserJobRecruit.js');


class T200HomeJobRecruitIndex extends T200HomeUserBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);
    }

    load_index() {
        log(__filename, "load");
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let data = {};

            self.load_recruit_full(data).then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.load_recruit_part(data);
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

    

    load_recruit_full(data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let job = new T200UserJobRecruit();
            job._type = "type_full";
            job._fields = job.list_fields();
            return self.list(job.merge_user_paging_type_list()).then(function(values){
                data.job_fulls = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    load_recruit_part(data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let job = new T200UserJobRecruit();
            job._type = "type_part";
            job._fields = job.list_fields();
            return self.list(job.merge_user_paging_type_list()).then(function(values){
                data.job_parts = values;
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200HomeJobRecruitIndex;