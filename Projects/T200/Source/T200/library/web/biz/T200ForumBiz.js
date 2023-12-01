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
            model.paging_count_sql = model.board_count_sql;
            model.merge_paging = model.merge_board;
            self.paging(model).then(function(data){
                resolve(data);
            }, function(err){
                reject();
            });
        });

        return promise;
    }
    
    /*
    board(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                if(self.store.is_connected()){
                    return self.board_done(model).then(resolve, reject);
                }else{
                    return self.store.connect().then(function(){
                        return self.board_done(model).then(resolve, reject);
                    }, function(err){
                        reject();
                    }).catch(function(err){
                        reject();
                    }).finally(function(){
                        self.store.disconnect().then(function(){

                        }, function(){

                        });
                    });
                }
            }else{
                reject();
            }
        });

        return promise;
    }

    board_done(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.paging(model).then(function(data){
                if(data){
                    resolve(data);
                }else{
                    reject();
                }            
            }, function(err){
                reject();
            });
        });

        return promise;
    }
    */

}

module.exports = T200ForumBiz;