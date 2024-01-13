const T200Tag = require('../T200Tag.js');


class T200Link extends T200Tag {
    constructor() {
        super();
    }

    create(element) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.url = element.url;
            self.name = element.name;
            self.type = element.type;
            self.target = element.target;
            self.value = element.value;
            self.locate = element.locate;

            let name = self.type;

            switch(self.target){
                case undefined:
                    break;
                case 'blank':
                    name = "link_blank";
                    break;
                case 'self':
                    //name = "link_blank";
                    break;
                case 'parent':
                    //name = "link_blank";
                    break;
                case 'top':
                    //name = "link_blank";
                    break;
            }
            
            let result = true;
            await self.create_flow(name).then(function(){

            }, function(err){
                result = false;
            });

            await self.create_tag().then(function(){

            }, function(err){
                result = false;
            });

            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }


    
    run(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browser = browser;
            self.flow.execute(browser, self).then(function(){
                global.final.set_entry(self.project, self.page, self.name, true);
                resolve();
            }, function(err){
                global.final.set_failure(self.project, self.page, self.name);
                reject();
            });
        });

        return promise;
    }

}

module.exports = T200Link;