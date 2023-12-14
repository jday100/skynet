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

    static verify_null(value) {
        if(undefined == value || null == value){
            return false;
        }

        return true;
    }

    static verify_status(value) {
        if(value){
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

    static verify_zero(value) {
        if(0 == value){
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

    static verify_text(value) {
        if(value){
            return true;
        }

        return false;
    }

    static verify_empty(value) {
        if(undefined == value){
            return false;
        }

        return true;
    }

    static verify_texts_6(value) {
        if(value && 6 == value.length){
            return true;
        }
        return false;
    }

    static verify_texts_12(value) {
        if(value && 12 == value.length){
            return true;
        }
        return false;
    }

    static verify_texts(short, long, value) {
        if(value && short <= value.length && long >= value.length){
            return true;
        }
        return false;
    }

    static verify_text_50(value) {
        if(value && 50 >= value.length){
            return true;
        }

        return false;
    }

    static verify_text_100(value) {
        if(value && 100 >= value.length){
            return true;
        }

        return false;
    }

    static verify_text_255(value) {
        if(value && 255 >= value.length){
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