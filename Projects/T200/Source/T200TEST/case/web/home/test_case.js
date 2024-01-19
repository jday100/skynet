const thread = require('child_process');
const T200Web = require('../../../library/web/T200Web.js');


class T200HomeWeb extends T200Web {
    constructor() {
        super();

        this.html = [
            "/register.html",
            "/login.html",
            "/content/person/profile_init.html",
            "/content/person/identity_init.html"
        ]

        this.next = "/content/person/profile_init_html";
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
}

module.exports = T200HomeWeb;