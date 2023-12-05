const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200PagingBiz = require('./T200PagingBiz.js');


class T200SearchBiz extends T200PagingBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);

        this.search = request.get("search");
    }

    fulltext2(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            model.merge_paging_count = model.merge_fulltext_count;
            model.merge_paging_list = model.merge_fulltext_list;
            self.paging2(model).then(function(data){
                resolve(data);
            }, function(err){
                reject();
            });
        });

        return promise;
    }


    fulltext(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            model.paging_count_sql = model.fulltext_count_sql;
            model.merge_paging = model.merge_fulltext;
            self.paging(model).then(function(data){
                resolve(data);
            }, function(err){
                reject();
            });
        });

        return promise;
    }
    
}

module.exports = T200SearchBiz;