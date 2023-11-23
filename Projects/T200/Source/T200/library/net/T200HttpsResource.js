const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');

const path = require('path');

const T200File = require('../fs/T200File.js');
const T200Path = require('../fs/T200Path.js');


class T200HttpsResource {
    constructor() {

    }

    exists(file) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let real = T200Path.join_root(file);
            log(__filename, "exists", file);
            T200File.exists(real).then(resolve, reject);
        });

        return promise;
    }

    isdir(file) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let real = T200Path.join_root(file);
            log(__filename, "isdir", file);
            T200Path.isdir(function(flag){
                resolve(flag);
            }, function(){
                reject();
            }).catch(function(err){
                reject();
            });
        });

        return promise;
    }

    load_action(file) {
        let name = T200Path.join_root(file);
        
        let result;
        let biz;

        try{
            biz = require(name);
        }catch(err){
            console.log(err);
            throw err;
        };

        log(__filename, "load_action", file);
        if(biz){
            result = true;
        }else{
            result = false;
        }

        return result;
    }

    load_file(file) {
        let real = T200Path.join_root(file);
        log(__filename, "load_file", file);
        return T200File.load(real);
    }

    merge_index(url) {
        let files = global.setup.https.index.split(',');
        let result = new Array();

        log(__filename, "merge_index", url);
        for(let file of files){
            let name = path.join(url, file);
            result.push(name);
        }

        return result;
    }

    merge_action(url) {
        log(__filename, "merge_action", url);
        return path.join(global.setup.https.actions, url + '.js');
    }

    merge_html(url) {
        log(__filename, "merge_html", url);
        return path.join(global.setup.https.home, url);
    }   

    merge_app() {
        log(__filename, "merge_app", "app.js");
        return path.join(global.setup.https.actions, '/app.js');
    }

    merge_pages(url) {
        log(__filename, "merge_pages", url);
        return path.join(global.setup.https.pages, "/" + url);
    }

}

module.exports = T200HttpsResource;