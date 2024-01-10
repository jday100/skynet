const T200Error = require('../T200Error.js');
const fs = require('fs');
const path = require('path');


class T200Path {
    constructor() {

    }

    static exists(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            try{
                fs.lstat(name, function(err, stats){
                    if(err){
                        reject(T200Error.build());
                    }else{
                        if(stats.isDirectory()){
                            resolve(true);
                        }else{
                            resolve(false);
                        }
                    }
                });
            }catch(err){
                reject(T200Error.build());
            };
        });

        return promise;
    }

    static create(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            try{
                fs.mkdir(name, function(err){
                    if(err){
                        reject(T200Error.build());
                    }else{
                        resolve();
                    }
                });
            }catch(err){
                reject(T200Error.build());
            };
        });

        return promise;
    }

    static is_dir(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            try{
                fs.lstat(name, function(err, stats){
                    if(err){
                        reject(T200Error.build());
                    }else{
                        if(stats.isDirectory()){
                            resolve(true);
                        }else{
                            resolve(false);
                        }
                    }
                });
            }catch(err){
                reject(T200Error.build());
            };
        });

        return promise;
    }

    static join_root(file) {
        let name = "../../" + file;
        return path.join(__dirname, name);
    }

    static list(dir) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result_dirs = new Array();
            let result_files = new Array();
            try{
                const files = fs.readdirSync(dir);

                for(let file of files){
                    let name = `${dir}\\${file}`;
                    const stat = fs.statSync(name);

                    if(stat.isDirectory()){
                        result_dirs.push(file);
                    }else{
                        result_files.push(file);
                    }
                }

                let result = {};
                result.dirs = result_dirs;
                result.files = result_files;
                resolve(result);
            }catch(err){
                reject(T200Error.build());
            };
        });

        return promise;
    }
    
}

module.exports = T200Path;