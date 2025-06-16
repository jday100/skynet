const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');


class T200StoreBase {
    constructor(client) {
        this._client = client;
        this._connected = false;
    }

    check() {
        if(undefined == this._client){
            
        }else{
            return true;
        }

        return false;
    }

    is_connected() {
        if(this._client && this._client._conn){
            return true;
        }

        return false;
    }

    connect() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                self._client.connect().then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    disconnect() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                self._client.disconnect().then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    query(sql) {
        log(__filename, "query", sql);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                self._client.query(sql).then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    execute(sql) {
        log(__filename, "execute", sql);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                self._client.execute(sql).then(resolve, reject);
            }else{
                reject();
            }
        });

        return promise;
    }

    begin() {
        let self = this;
        let promise = new Promise(function(resolve, reject){

        });

        return promise;
    }

    commit() {
        let self = this;
        let promise = new Promise(function(resolve, reject){

        });

        return promise;
    }

    rollback() {
        let self = this;
        let promise = new Promise(function(resolve, reject){

        });

        return promise;
    }


    ///
    /*
    inner_join(model1, fields1, model2, fields2, where, order, limit) {

    }
    inner_join(article, user, on(equal(article.userid, user.userid)), where(equel(user.userid, 1)), desc(user.userid). limit(10), offset(0))

    select(fields(*), from('article'), inner_join());


    select * from table t1 inner join person t2 on t1.userid = t2.userid where match() against() order by userid desc limit 1 offset 1;

    select(fields(*), from(table), inner_join(person), on(equal(userid, userid)), where(match(), against()), order(desc(userid)), limit(1), offset(1));
    */
}

module.exports = T200StoreBase;