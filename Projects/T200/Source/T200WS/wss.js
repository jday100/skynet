const crypto = require('crypto');


class Wss {
    constructor(req, res) {
        this.req = req;
        this.res = res;
    }

    open() {
    }

    upgrade() {
        let key = this.req.headers['sec-websocket-key'];
        let value = key + "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
        let result = crypto.createHash("sha1").update(value).digest("base64");
        this.res.write([
            "HTTP/1.1 101 Switchng Protocols",
            "Upgrade: websocket",
            "Connection: Upgrade",
            "Sec-WebSocket-Accept: " + result
        ].join("\n") + "\n\n");

        this.res.on("data", function(chunk){
            console.log(2);

        });

        this.res.on("end", function(){
            console.log('end');
        });

        this.res.on("error", function(err){
            console.log("error");
        });
    }
}

module.exports = Wss;