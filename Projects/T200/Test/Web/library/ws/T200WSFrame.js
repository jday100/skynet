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
            if(1 == mask){
                frame.mask = new Array();
                frame.mask.push(chunk[4]);
                frame.mask.push(chunk[5]);
                frame.mask.push(chunk[6]);
                frame.mask.push(chunk[7]);

                length = chunk[2] << 8;
                length += chunk[3];

                frame.text = new Array();

                for(let i=0;i<length;i++){
                    frame.text.push(chunk[8 + i]);
                }

                let text = new Array();
                T200WSFrame.mask(frame.text, frame.mask, text);

                frame.text = "";

                for(let i=0;i<length;i++){
                    let value = String.fromCharCode(text[i]);
                    frame.text += value;
                }
            }else{
                
            }
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
                    let value = String.fromCharCode(text[i]);
                    frame.text += value;
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

    static text(value) {
        let length = value.length;

        if(125 < length && 65536 > length) {
            let frame = Buffer.alloc(length + 4);

            frame[0] = 0b10000001;
            frame[1] = 126;
            frame[3] = length & 255;
            frame[2] = length >> 8;

            for(let i=0;i<length;i++){
                let data = value.charCodeAt(i);
                frame[i+4] = data;
            }

            return frame;
        }else{
            let frame = Buffer.alloc(length + 2);

            frame[0] = 0b10000001;
            frame[1] = length;

            for(let i=0;i<length;i++){
                let data = value.charCodeAt(i);
                frame[i+2] = data;
            }

            return frame;
        

            /*
            let frame = new Uint8Array();

            frame.push(0b10000001);
            frame.push(length);

            for(let i=0;i<length;i++){
                frame.push(value[i]);
            }
            return frame;
            */
        }   
    }
}

module.exports = T200WSFrame;