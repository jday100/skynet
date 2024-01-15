const { resolveObjectURL } = require('buffer');
const thread = require('child_process');


class T200WebLoader {
    constructor() {

    }

    start() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let result = true;
            setTimeout(function(){
                thread.exec(`cd ../web/ && node ./T200Home.js`, function(err, stdin , stdout){
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

                //resolve();
                setTimeout(function(){
                    if(result){
                        resolve();
                    }
                }, 5000);
            });
        });

        return promise;
    }

    stop() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            if(undefined == self.server){
                resolve();
            }else{
                await self.server.kill().then(function(){
                    resolve();
                }, function(err){
                    reject();
                });
            }
        });

        return promise;
    }
}

module.exports = T200WebLoader;