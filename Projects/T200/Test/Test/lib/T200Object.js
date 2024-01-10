class T200Object {
    constructor() {

    }

    static run(obj) {
        let names = Object.getOwnPropertyNames(Object.getPrototypeOf(obj));
        let result = new Array();

        for(let element of names){
            if(element && 'run' == element){
                result.push(element);
            }
        }

        return result;
    }

    static test(obj) {
        let names = Object.getOwnPropertyNames(Object.getPrototypeOf(obj.super()));
        let result = new Array();

        for(let element of names){
            if(element && 'test_case' == element){
                result.push(element);
            }
        }

        return result;
    }
}

module.exports = T200Object;