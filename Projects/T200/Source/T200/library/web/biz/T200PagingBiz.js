const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200BizBase = require('./T200BizBase.js');


class T200PagingBiz extends T200BizBase {
    constructor(request, cookie, session) {
        super();
        this.request = request;
        this.cookie = cookie;
        this.session = session;

        this._page = request.get("page");

        this._paging_count_name = "merge_paging_count";
        this._paging_list_name = "merge_paging_list";
    }


    paging(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.count(model.paging_count_sql).then(function(total){
                model._total = total;
                self.calculate(model);
                model._offset = model.paging.offset;
                model.paging_list_sql = model.merge_paging(model._offset);
                return self.list(model.paging_list_sql).then(function(value){
                    let data = {};
                    data.paging = model.paging;
                    data.values = value;
                    resolve(data);
                }, function(err){
                    reject();
                });
            }, function(err){
                reject();
            });
        });

        return promise;
    }


    calculate(model) {
        //let page = model._page;
        let page = this.request.get("page");
        let total = model._total;

        let prev = page - 1;
        let next = page + 1;

        let paging = {};

        paging.first = 1;
        paging.last = Math.ceil(total / model._page_size);
        if(0 == paging.last){
            paging.last = 1;
        }

        paging.prev = prev < paging.first ? paging.first : prev;
        paging.next = next > paging.last ? paging.last : next;

        let head = Math.floor(page / model._page_size) * model._page_size;
        let tail = head + model._page_size;

        head = 0 == head ? 1 : head;
        paging.pages = new Array();

        for(let i = head;i <= tail;i++){
            if(i > paging.last){
                break;
            }else{
                paging.pages.push(i);
            }
        }

        paging.offset = (page - 1) * model._page_size;

        model.paging = paging;
    }



    /*
    list(user) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                if(self.store.is_connected()){
                    return self.list_done(user).then(resolve, reject);
                }else{
                    return self.store.connect().then(function(){
                        return self.list_done(user).then(resolve, reject);
                    }, function(err){
                        reject();
                    }).catch(function(err){
                        console.log(err);
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

    list_done(user) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.store.query(user.merge_list()).then(function(data){
                let result = typeof(data);
                console.log(result)
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

    count() {

    }

    paging(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = false;
            if(self.check()){
                if(self.store.is_connected()){
                    return self.count_done(model).then(function(total){
                        model._total = total
                        return self.paging_done(model).then(function(value){
                            model.data = value;
                            
                            let data = {};
                            data.paging = model.paging;
                            data.values = model.data;
                            resolve(data);
                        }, function(){

                        });
                    }, function(){
                        
                    });
                }else{
                    self.store.connect().then(function(){
                        return self.count_done(model).then(function(total){
                            model._total = total;
                            return self.paging_done(model).then(function(value){
                                model.data = value;
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
                            data.values = model.data;
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

    calculate(model) {
        //let page = model._page;
        let page = this.request.get("page");
        let total = model._total;

        let prev = page - 1;
        let next = page + 1;

        let paging = {};

        paging.first = 1;
        paging.last = Math.ceil(total / model._page_size);
        if(0 == paging.last){
            paging.last = 1;
        }

        paging.prev = prev < paging.first ? paging.first : prev;
        paging.next = next > paging.last ? paging.last : next;

        let head = Math.floor(page / model._page_size) * model._page_size;
        let tail = head + model._page_size;

        head = 0 == head ? 1 : head;
        paging.pages = new Array();

        for(let i = head;i <= tail;i++){
            if(i > paging.last){
                break;
            }else{
                paging.pages.push(i);
            }
        }

        model.paging = paging;
    }

    count_done(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.store.query(model.merge_count()).then(function(data){
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

    paging_done(model) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.calculate(model);
            return self.store.query(model.merge_paging()).then(function(data){
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

module.exports = T200PagingBiz;