const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200PagingBiz = require('./T200PagingBiz.js');


class T200SearchBiz extends T200PagingBiz {
    constructor(request, cookie, session) {
        super(request, cookie, session);

        this.search = request.get("search");
    }
    
    fulltext(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = false;
            if(self.check()){
                if(self.store.is_connected()){
                    self.fulltext_count_done(model).then(function(total){
                        model._total = total
                        self.fulltext_paging_done(model).then(function(){

                        }, function(){

                        });
                    }, function(){
                        
                    });
                }else{
                    self.store.connect().then(function(){
                        return self.fulltext_count_done(model).then(function(total){
                            model._total = total;
                            return self.fulltext_paging_done(model).then(function(value){
                                model.values = value;
                                result = true;
                            }, function(){
    
                            });
                        }, function(){
                        
                        }).finally(function(){
                            self.store.disconnect().then(function(){
    
                            }, function(){
    
                            });
                        });
                    }, function(){

                    }).finally(function(){
                        if(result){
                            let data = {};
                            data.paging = model.paging;
                            data.values = model.values;
                            resolve(data);
                        }else{
                            reject();
                        }
                    });
                }
            }else{
                reject();
            }
        });

        return promise;
    }

    fulltext_count_done(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.store.query(model.merge_fulltext_count(self.search)).then(function(data){
                if(data && 1 == data.length){
                    let result = Number(data[0].total);
                    resolve(result);
                }else{
                    reject();
                }            
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    fulltext_paging_done(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.calculate(model);
            return self.store.query(model.merge_fulltext_paging(self.search)).then(function(data){
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
}

module.exports = T200SearchBiz;