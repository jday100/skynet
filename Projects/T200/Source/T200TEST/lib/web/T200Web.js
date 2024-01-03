const T200Define = require('../../lib/T200Define.js');

class T200Web {
    constructor(objects) {
        let self = this;
        self.objects = new Array();

        for(let element of objects){
            T200Define.create(element).then(function(data){
                let value = data.toString();
                let obj = JSON.parse(value);
                if(undefined == obj){

                }else{
                    self.objects.push(obj);
                }
            }, function(err){

            });
        }
    }

    test() {
        let self = this;

        for(let obj of self.objects) {
            for(let field of obj){
                console.log(field);
            }
        }


        //let id = self.browser.id("home");
        //let obj = self.browser.find(id);

        //let obj = self.browser.field("", "");

        //if(obj)obj.click();

        let obj = self.browser.browser.findElements(self.browser.by().css("a[locale='home']"));

        //if(obj)obj.click();

        let home = self.browser.find(self.browser.css("a[locale='home']"));

        if(home)home.click();

        //sleep(1);

        //console.log(self.browser.browser.current_url);

        //self.browser.browser.wait(self.browser.untils().titleIs(''), 1000);
        self.browser.browser.wait(function(){
            console.log(self.browser.browser.currentUrl);
            return true;
        }, 1000);
    }
}

module.exports = T200Web;