const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

/*
base:
    check
    append
    modify
    remove
    search
    list
    load
    count

paging:
    paging

search:
    fulltext

forum:
    board

visiter:
    list
    load

user:
    load

admin:
    load
*/


class T200BizBase {
    constructor() {

    }

    check() {
        if(undefined == this.store){
            
        }else{
            return true;
        }

        return false;
    }

    append(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()) {
                self.store.command(sql).then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    modify(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()) {
                self.store.command(sql).then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    remove(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()) {
                self.store.command(sql).then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    search(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()) {
                self.store.select(sql).then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    list(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()) {
                self.store.select(sql).then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    load(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()) {
                self.store.select(sql).then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    count(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()) {
                self.store.select(sql).then(function(data){
                    if(data && 1 == data.length){
                        let total = Number(data[0].total);
                        resolve(total);
                    }else{
                        reject();
                    }
                }, function(err){
                    reject();
                });
            }else{
                reject();
            }
        });

        return promise;
    }





    /*
    load(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                self.store.load(sql).then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }
    */

}

module.exports = T200BizBase;