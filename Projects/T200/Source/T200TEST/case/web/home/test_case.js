const thread = require('child_process');
const T200Web = require('../../../library/web/T200Web.js');
const T200Source = require('../../../library/T200Source.js');


class T200HomeWeb extends T200Web {
    constructor() {
        super();

        this.html = [
            "/register.html",
            "/login.html",
            "/content/person/profile_init.html",
            "/content/person/identity_init.html",
            "/content/person/profile.html",
            "/content/house/rent.html",
            "/content/house/rent_edit.html"
        ]

        this.next = "";


        this.view = [
            "/login.html"
        ]
    }

    create() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await self.#build_db().then(resolve, reject);
        });

        return promise;
    }

    #build_db() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;

            setTimeout(function(){
                thread.exec(`cd ../web/ && node ./project/init/T200HomeDatabase1.js`, function(err, stdin, stdout){
                    console.log(err);

                    //test
                    resolve();
                    return;

                    if(err){
                        reject();
                    }else{
                        resolve();
                    }
                });

                setTimeout(function(){
                    if(result){
                        resolve();
                    }
                }, 15000);
            });
        });

        return promise;
    }

    test_view(browser) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            let flag = true;
            for(let html of self.view){
                if(flag){
                    await browser.get(browser.url(html)).then(function(){

                    }, function(err){
                        result = false;
                    }).then(function(){
                        return browser.sleep(1000);
                    }, function(err){
                        result = false;
                    }).then(function(){
                        flag = false;
                    }, function(err){
                        result = false;
                    });
                }
                if(result){
                    await T200Source.create_web(self.project, html).then(async function(obj){
                        await obj.test_view(browser).then(function(){
        
                        }, function(err){
                            result = false;
                        }).finally(function(){
               
                        });
                    }, function(err){
                        result = false;
                    });
                }
                
                if(!result)break;
            }
            if(result){
                resolve();
            }else{
                reject();
            }
        });

        return promise;
    }
}

module.exports = T200HomeWeb;