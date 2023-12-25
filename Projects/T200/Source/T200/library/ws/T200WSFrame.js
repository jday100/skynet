const uuid = require('uuid');
const crypto = require('crypto');

class T200WSFrame {
    constructor() {

    }

    static upgrade(req) {
        let key = req.headers['sec-websocket-key'];
        let value = key + "258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
        let result = crypto.createHash("sha1").update(value).digest("base64");
    
        let frame = [
            "HTTP/1.1 101 Switchng Protocols",
            "Upgrade: websocket",
            "Connection: Upgrade",
            "Sec-WebSocket-Accept: " + result
        ].join("\n") + "\n\n";

        return frame;
    }

    static parse(chunk) {
        let frame = {};
        let fin = T200WSFrame.parse_fin(chunk);

        if(1 == fin){
            let opcode = T200WSFrame.parse_opcode(chunk);
            let mask = T200WSFrame.parse_mask(chunk);
            let length = T200WSFrame.parse_length(chunk);

            if(1 == mask){
                switch(opcode){
                    case 1:
                        frame.opcode = opcode;
                        T200WSFrame.parse_text(chunk, frame);
                        break;
                    case 8:
                        
                        break;
                }
            }

        }else{

        }

        return frame;
    }

    static parse_fin(chunk) {
        let byte = chunk[0];

        let result = (byte & 0b10000000) >> 7;

        return result;
    }


    static parse_type(chunk) {
        let byte = chunk[0];

        let id = byte & 0x1111;

        return id;
    }

    static parse_opcode(chunk) {
        let byte = chunk[0];

        let result = byte & 0b1111;

        return result;
    }

    static parse_mask(chunk) {
        let byte = chunk[1];

        let result = (byte & 0b10000000) >> 7;

        return result;
    }

    static parse_length(chunk) {
        let byte = chunk[1];

        let result = byte & 0b1111111;

        if(126 == result){
            let length = chunk[2] < 8 + chunk[3];
        }else if(127 == result){

        }else if(126 > result){

        }else{

        }

        return result;
    }

    static parse_text(chunk, frame) {
        let mask = T200WSFrame.parse_mask(chunk);
        let length = T200WSFrame.parse_length(chunk);

        if(126 == length){

        }else if(127 == length){

        }else if(126 > length){
            if(1 == mask){
                frame.mask = new Array();
                frame.mask.push(chunk[2]);
                frame.mask.push(chunk[3]);
                frame.mask.push(chunk[4]);
                frame.mask.push(chunk[5]);

                frame.text = new Array();

                for(let i=0;i<length;i++){
                    frame.text.push(chunk[6 + i]);
                }

                let text = new Array();
                T200WSFrame.mask(frame.text, frame.mask, text);

                frame.text = "";

                for(let i=0;i<length;i++){
                    frame.text += String.fromCharCode(text[i]);
                }
            }else{
                
            }
        }else{

        }
    }

    static mask(source, mask, target) {
        let length = source.length;

        for(let i=0;i<length;i++){
            target.push(source[i] ^ mask[i % 4]);
        }
    }
}

module.exports = T200WSFrame;