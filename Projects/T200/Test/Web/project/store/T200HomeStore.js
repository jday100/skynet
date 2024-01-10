const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');

const T200StoreBiz = require('../../library/web/store/T200StoreBase.js');


class T200HomeStore extends T200StoreBiz {
    constructor() {
        super();
        this._client = global.database.client();
    }


    select(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                let result = false;
                let data;
                if(self.is_connected()){
                    self.query(sql).then(function(value){
                        resolve(value);
                    }, function(err){
                        reject();
                    }).finally(function(){

                    });
                }else{
                    self.connect().then(function(){
                        return self.query(sql).then(function(value){
                            result = true;
                            data = value;
                        }, function(err){

                        }).finally(function(){
                            return self.disconnect().then(function(){

                            }, function(err){
                                result = false;
                            });
                        });
                    }, function(err){
                        
                    }).finally(function(){
                        if(result){
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


    command(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(self.check()){
                let result = false;
                let data;
                if(self.is_connected()){
                    self.execute(sql).then(function(value){
                        resolve(value);
                    }, function(err){
                        reject();
                    }).finally(function(){

                    });
                }else{
                    self.connect().then(function(){
                        return self.execute(sql).then(function(value){
                            result = true;
                            data = value;
                        }, function(err){

                        }).finally(function(){
                            return self.disconnect().then(function(){

                            }, function(err){
                                result = false;
                            });
                        });
                    }, function(err){
                        
                    }).finally(function(){
                        if(result){
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






    /*
    load(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = false;
            let data;
            if(self.check()){
                if(self.is_connected()){
                    return self.load_done(sql).then(resolve, reject);
                }else{
                    return self.connect().then(function(){
                        return self.load_done(sql).then(function(value){
                            data = value;
                            result = true;
                        }, function(){

                        }).finally(function(){
                            return self.disconnect().then(function(){

                            }, function(){
                                result = false;
                            });
                        });
                    }, function(){

                    }).finally(function(){
                        if(result){
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

    load_done(sql) {
        let self = this;
        return self.query(sql);
    }

    
    insert(sql) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = false;
            let data;
            if(self.check()){
                if(self.is_connected()){
                    return self.execute(sql).then(resolve, reject);
                }else{
                    return self.connect().then(function(){
                        return self.execute(sql).then(function(value){
                            data = value;
                            result = true;
                        }, function(){

                        }).finally(function(){
                            return self.disconnect().then(function(){

                            }, function(){
                                result = false;
                            });
                        });
                    }, function(){

                    }).finally(function(){
                        if(result){
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
    */

}

module.exports = T200HomeStore;