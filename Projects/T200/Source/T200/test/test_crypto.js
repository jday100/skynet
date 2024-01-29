const crypto = require('crypto');


console.log(crypto.getHashes());

console.log(crypto.getCiphers());

const  crypto = require('crypto');

let data = "你好";

let key = "01234567890123456789012345678901";
let iv = "0123456789012345";

let cipher = crypto.createCipheriv('aes-256-cbc', key, iv);

let crypted = cipher.update(data, 'utf8');

crypted = cipher.final('base64');

console.log(crypted);


let decipher = crypto.createDecipheriv('aes-256-cbc', key, iv);

let decrypt = decipher.update(crypted, 'base64');

decrypt = decipher.final('utf8');

console.log(decrypt);
