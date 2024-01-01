/*
let name = Object.getOwnPropertyNames(Object.getPrototypeOf(test));

console.log(name);
*/

class T200Object {
    constructor() {

    }

    static methods(obj) {
        let names = Object.getOwnPropertyNames(Object.getPrototypeOf(obj));
        let result = new Array();

        for(let element of names){
            if(element 
                && (
                    element.startsWith("test_") 
                    || element.startsWith("run_")
                )){
                result.push(element);
            }
        }

        return result;
    }
}

module.exports = T200Object;
