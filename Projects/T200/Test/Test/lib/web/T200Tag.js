const T200Flow = require('../flow/T200Flow.js');


class T200Tag {
    constructor() {

    }

    create_tag() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let page = global.final.find_page(self.project, self.page);

            if(page){
                global.final.append_entry(page, self);
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }

    create_flow(name) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let flow = new T200Flow(name);

            flow.create().then(function(){
                self.flow = flow;
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    get(url) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let page = self.browser.url(url);
            self.browser.get(page).then(function(){

            }, function(err){

            }).then(function(){
                return self.browser.sleep(1000);
            }, function(err){

            }).then(function(){
                return self.browser.get_current_url();
            }, function(err){

            }).then(function(url){
                if(url == page){
                    resolve();
                }else{
                    reject();
                }
            }, function(err){

            });
        });

        return promise;
    }

    click() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browser.locate(self.locate).then(function(element){
                if(undefined == element){

                }else{
                    return element.click();
                }                
            }, function(err){

            }).then(function(){
                return self.browser.sleep(1000);
            }, function(err){

            }).then(function(){
                return self.browser.get_current_url();
            }, function(err){

            }).then(function(url){
                if(url == self.browser.url(self.value)){
                    resolve();
                }else{
                    reject();
                }
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    change(handle) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browser.change(handle).then(function(){

            }, function(err){

            }).then(function(){
                return self.browser.get_current_url();
            }, function(err){

            }).then(function(url){
                if(url == self.browser.url(self.value)){
                    resolve();
                }else{
                    reject();
                }
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    get_new_window() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            resolve();
        });

        return promise;
    }
}

module.exports = T200Tag;