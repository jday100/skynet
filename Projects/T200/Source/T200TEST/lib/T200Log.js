
class T200Log {
    constructor() {

    }

    static m_flag = false;

    static log(msg) {
        if(T200Log.m_flag){
            console.log(`error : ${msg}`);
        }else{
            console.log(msg);
        }
    }

    static result(msg) {
        T200Log.m_flag = true;
        console.log(msg);
    }
}

module.exports = T200Log;