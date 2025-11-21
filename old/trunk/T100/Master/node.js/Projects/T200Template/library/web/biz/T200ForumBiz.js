const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200SearchBiz = require('./T200SearchBiz.js');


class T200ForumBiz extends T200SearchBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);

        this._paging_count_name = "merge_board_count";
        this._paging_list_name = "merge_board_list";
    }

    board(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            model.merge_paging_count = model.merge_board_count;
            model.merge_paging_list = model.merge_board_list;
            self.paging2(model).then(function(data){
                resolve(data);
            }, function(err){
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200ForumBiz;