const T200Setup = require('../project/T200Setup.js');
const T200Object = require('./T200Object.js');

const T200File = require(T200Setup.external('./library/fs/T200File.js'));

const T200Obejct = require('./T200Object.js');


class T200Source {
    constructor() {

    }

    run(source, method) {
        if(undefined == source){
            return;
        }

        //test
        source = "./case/T200About.js";

        T200File.exists(source).then(function(){
            source = "../" + source;
            const target = require(source);

            if(undefined == target){

            }else{
                let obj = new target();

                if(undefined == obj){

                }else{
                    let methods = T200Object.methods(obj);

                    if(undefined == methods){

                    }else{
                        for(let element of methods){
                            obj[element]();
                        }
                    }
                }
            }
        }, function(){

        });
    }
}

module.exports = T200Source;