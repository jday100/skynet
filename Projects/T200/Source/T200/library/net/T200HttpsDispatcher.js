const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const url = require('url');
const T200Path = require('../fs/T200Path.js');


class T200HttpsDispatcher {
    constructor() {

    }

    run(req, res) {
        log(__filename, "dispatcher run");

            let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.dispense(req).then(function(data){
                log(__filename, "dispense success");
                resolve(data);
            }, function(err){
                log(__filename, "dispense failure");
                reject(err);
            }).catch(function(err){
                reject(err);
            });
        });

        return promise;
    }

    dispense(req) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let flag;
            let data = url.parse(req.url, true);

            flag = req.method;

            log(__filename, "dispense", flag);

            switch(flag){
                case 'GET':
                    return self.assign_get(data.pathname).then(resolve, reject).catch(reject);
                    break;
                case 'POST':
                    return self.assign_post(data.pathname).then(resolve, reject);
                    break;
            }

        });

        return promise;
    }

    assign_get(action) {
        log(__filename, "assign_get", action);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let done = global.action.get[action];

            if(done){
                done(self.request, self.response, self.cookie, self.session, self.resource).then(function(data){
                    resolve(data);
                }, function(err){
                    reject(err);
                });
            }else{
                return self.assign_path(action).then(function(data){
                    resolve(data);
                }, function(err){
                    reject(err);
                }).catch(function(err){
                    console.log(err);
                    reject(err);
                });
            }
        });

        return promise;
    }

    assign_post(action) {
        log(__filename, "assign_post", action);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let done = global.action.post[action];

            if(done){
                done(self.request, self.response, self.cookie, self.session, self.resource).then(function(data){
                    resolve(data);
                }, function(err){
                    reject();
                });
            }else{
                self.response.status(500);
                reject(500);
            }
        });

        return promise;
    }

    assign_index(action) {
        log(__filename, "assign_index", action);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.resource.isdir(action).then(function(result){
                if(result){
                    return self.search_index(action).then(function(file){
                        return self.load_html(file).then(function(data){
                            resolve(data);
                        }, function(){
                            return error();
                        });
                    }, function(err){
                        return error();
                    }).catch(function(err){
                        return error();
                    });
                }else{
                    return error();
                }
            
            }, function(err){
                reject();
            }).catch(function(err){
                reject();
            });

        });

        return promise;
    }

    assign_path(action) {
        log(__filename, "assign_path", action);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            if(action.endsWith('/')){
                return self.assign_index(action).then(resolve, reject).catch(reject);
            }else{
                return self.assign_file(action).then(function(data){
                    resolve(data);
                }, function(err){
                    return self.assign_index(action).then(resolve, reject);
                });
            }
            
        });

        return promise;
    }

    assign_file(action) {
        log(__filename, "assign_file", action);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let real = self.resource.merge_html(action);
            return self.resource.exists(real).then(function(){
                return self.sorting_file(action);
            }, function(err){
                reject(err);
            }).then(function(data){
                resolve(data);
            }, function(){
                reject();
            });
        });

        return promise;
    }

    search_index(action) {
        log(__filename, "search_index", action);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let files = self.resource.merge_index(action);
            let items = new Array();

            for(let file of files) {
                let name = self.resource.merge_html(file);
                let task = self.search_file(name);
                items.push(task);
            }

            const result = Promise.any(items);

            result.then(function(data){
                resolve(data);
            }, function(err){
                self.response.status(404);
                reject(err);
            });
        });

        return promise;
    }

    search_file(file) {
        log(__filename, "search_file", file);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.resource.exists(file).then(function(){
                console.log(file);
                resolve(file);
            }, function(err){
                console.log(err);
                reject();
            }).catch(function(err){
                console.log(err);
                reject();
            });
        });

        return promise;
    }

    sorting_file(file) {
        log(__filename, "sorting_file", file);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.parse_type(file);
            return self.load_html(file).then(function(data){
                resolve(data);
            }, function(err){
                reject(err);
            });
        });

        return promise;
    }

    parse_type(file) {
        log(__filename, "parse_type", file);

        if(file.endsWith('.js')){
            this.response.set('Content-Type', 'application/javascript');
        }else if(file.endsWith('.css')){
            this.response.set('Content-Type', 'text/css');
        }
    }

    load_html(file) {
        log(__filename, "load_html", file);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let name = self.resource.merge_action(file);
            let html = self.resource.merge_html(file);
            
            return self.load_file(html).then(function(data){
                return self.resource.exists(name).then(function(){
                    return self.load_action(name);
                }, function(){

                }).then(function(){

                }, function(){
                    return error();
                }).catch(function(err){
                    log(__filename, "load_action error", err);
                }).finally(function(){
                    resolve(data);
                });
                
            }, function(err){
                reject(err);
            });
        });

        return promise;
    }

    load_action(action) {
        log(__filename, "load_action", action);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = self.resource.load_action(action);

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }

    load_file(file) {
        log(__filename, "load_file", file);
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return self.resource.load_file(file).then(function(data){
                resolve(data);
            }, function(err){
                reject(err);
            });
        });

        return promise;
    }

}

module.exports = T200HttpsDispatcher;