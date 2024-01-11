const T200Tag = require('../T200Tag.js');


class T200Link extends T200Tag {
    constructor() {
        super();
    }

    create(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.url = element.url;
            self.name = element.name;
            self.type = element.type;
            self.target = element.target;
            self.value = element.value;
            self.locate = element.locate;
            
            self.create_flow().then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }


    
    run(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browser = browser;
            self.flow.execute(browser, self).then(resolve, reject);
        });

        return promise;
    }

    run2(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browser = browser;
            self.get(self.url).then(function(){

            }, function(err){

            }).then(function(){
                return self.link_click();
            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }




    link_click() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            switch(self.target){
                case undefined:
                    self.click().then(resolve, reject);
                    break;
                case "_blank":
                    self.blank_click().then(resolve, reject);
                    break;
                case "_self":
                    self.click().then(resolve, reject);
                    break;
                case "_parent":
                    break;
                case "_top":
                    break;
                default:
                    break;
            }
        });

        return promise;
    }


    blank_click() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let item;
            let old_handles;
            let new_handles;
            let current;

            self.browser.get_window().then(function(){

            }, function(err){

            }).then(function(win){
                current = win;
                return self.browser.locate(self.locate);
            }, function(err){

            }).then(function(element){
                if(undefined == element){

                }else{
                    item = element;
                    if(undefined == self.target){
                    
                    }else if("blank" == self.target){
                        return self.browser.get_window_handles();
                    }
                }                
            }, function(err){

            }).then(function(wins){
                old_handles = wins;
                if(undefined == item){
                    reject();
                }else{
                    return item.click();
                }
            }, function(err){

            }).then(function(){
                return self.browser.sleep(1000);
            }, function(err){

            }).then(function(){
                if(undefined == self.target){
                    
                }else if("blank" == self.target){
                    return self.browser.get_window_handles();
                }
            }, function(err){

            }).then(function(wins){
                new_handles = wins;
                return self.get_new_windows(old_handles, new_handles);
            }, function(err){

            }).then(function(win){
                return self.browser.change(win);
            }, function(err){

            }).then(function(){
                return self.browser.get_current_url();
            }, function(err){

            }).then(function(url){
                if(url == self.browser.url(self.value)){

                }else{

                }
            }, function(err){

            }).then(function(){
                return self.browser.close();
            }, function(err){

            }).then(function(){
                return self.browser.change();
            }, function(err){

            }).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }



    run1(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            browser.get(browser.url(self.url)).then(function(){

            }, function(err){

            }).then(function(){
                return browser.sleep(1000);
            }, function(err){

            }).then(function(){
                return browser.locate(self.locate);
            }, function(err){

            }).then(function(element){
                if(undefined == element){

                }else{
                    return element.click();
                }
            }, function(err){

            }).then(function(){
                return browser.sleep(1000);
            }, function(err){

            }).then(function(){
                return browser.get_current_url();
            }, function(err){

            }).then(function(url){
                if(url == browser.url(self.value)){
                    resolve();
                }else{
                    reject();
                }
            }, function(err){

            }).finally(function(){
                return browser.get(browser.url(self.url));
            });
        });

        return promise;
    }
}

module.exports = T200Link;