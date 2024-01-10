class T200Tag {
    constructor() {

    }

    get(url) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browser.get(self.browser.url(url)).then(function(){

            }, function(err){

            }).then(function(){
                return self.browser.sleep(1000);
            }, function(err){

            }).then(function(){
                return self.browser.get_current_url();
            }, function(err){

            }).then(function(value){
                if(value == self.browser.url(self.url)){
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

    click() {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browser.locate(self.locate).then(function(element){
                return element;
            }, function(err){

            }).then(function(element){
                if(undefined == element){
                    reject();
                }else{
                    return element.click();
                }
            }, function(err){

            }).then(function(){
                return self.browser.sleep(1000);
            }, function(err){

            }).then(function(){
                if(undefined == self.target){
                    return undefined;
                }else if("blank" == self.target){
                    return self.browser.get_new_window();
                }
            }, function(err){

            }).then(function(win){
                if(undefined == win){
                    reject();
                }else{
                    return self.browser.get_current_url();
                }
            }, function(err){

            }).then(function(){
                
            }, function(err){

            });
        });

        return promise;
    }
}

module.exports = T200Tag;