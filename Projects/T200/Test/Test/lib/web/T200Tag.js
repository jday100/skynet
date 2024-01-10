class T200Tag {
    constructor() {

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