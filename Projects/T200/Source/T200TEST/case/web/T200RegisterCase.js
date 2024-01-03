const T200RegisterWeb = require('../../project/home/T200RegisterWeb.js');


class T200RegisterCase {
    constructor() {
        this.url = "/register.html";
    }

    run_register() {
        let self = this;

        self.get(self.url).then(function(){

        }, function(err){

        });
    }

    get(url) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.browser.get("http://localhost:8888" + url);



            //self.browser.findElement(self.browser.id("submit")).click();

            let id = self.browser.id("submit");
            let obj = self.browser.find(id);

            obj.click();


            let RegisterWeb = new T200RegisterWeb();

            RegisterWeb.browser = self.browser;
            RegisterWeb.test();

            /*
            for(let field of RegisterWeb.fields){
                self.set(field, self.value(field));
            }
            */
        });

        return promise;
    }

    set(field, value) {

    }

    value(field) {

    }
}

module.exports = T200RegisterCase;