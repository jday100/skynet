const T200Error = require('./T200Error.js');


class T200Dotter {
    constructor() {
        this._result = true;
        this._success = false;
        this._values = new Array();
    }

    hit(i) {
        console.log(`\thit => ${i}`);
        this._values.push(i);
    }

    success(i) {
        console.log(`\tsuccess => ${i}`);
        this._values.push(i);
        this._success = true;
        this._result = this._result ? true : false;
    }

    failure(i) {
        console.log(`\tfailure => ${i}`);
        this._values.push(i);
        this._result = false;
    }

    judge() {
        let prev = 0;
        let result = true;

        for(let item of this._values){
            console.log(item);
            if(prev < item){
                
            }else{
                result = false;
            }
            prev = item;
        }

        if(this._success){
            return this._result && result;
        }
        return false;
    }
}

module.exports = T200Dotter;