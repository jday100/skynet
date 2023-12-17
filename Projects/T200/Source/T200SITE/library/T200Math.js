const T200Error = require('./T200Error.js');


class T200Math {
    constructor() {

    }

    static random(min, max) {
        let range;
        let value;
        let result;

        if(max >= min){
            value = min;
            range = max - min;
        }else{
            value = max;
            range = min - max;
        }

        result = value + Math.round(Math.random() * range);
        return result;
    }
}

module.exports = T200Math;