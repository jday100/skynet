const { error, log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');


class T200HttpsForm {
    constructor() {

    }

    static verify_equal(value1, value2) {
        if(value1 && value2 && (value1 == value2)){
            return true;
        }

        return false;
    }    
    
    static verify_id(value) {
        if(value && 0 < value){
            return true;
        }

        return false;
    }

    static verify_ids(value) {
        if(value){
            return true;
        }

        return false;
    }

    static verify_text(value) {
        if(value){
            return true;
        }

        return false;
    }

    static verify_email(value) {
        if(value){
            return true;
        }

        return false;
    }
    
}

module.exports = T200HttpsForm;