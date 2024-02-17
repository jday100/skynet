const redis = require('redis');


class T200Redis {
    constructor() {

    }

    start() {
        let client = redis.createClient(6379, '127.0.0.1');

        client.on('err', err=>{
            console.log('err');
        });


        client.connect(6379, '127.0.0.1').then(function(){
            client.set("hello", 5).then(function(){
                console.log("ok");
            }, function(){

            })
        }, function(){

        });

        
    }

    stop() {

    }
}

module.exports = T200Redis;