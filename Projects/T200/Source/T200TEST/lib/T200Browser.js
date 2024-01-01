const T200Setup = require('../project/T200Setup.js');

const T200Path = require(T200Setup.external('./library/fs/T200Path.js'));
const T200Source = require('./T200Source.js');


class T200Browser {
    constructor(browser) {

    }

    static build(browser) {
        let result = new Array();

        if(undefined == browser){
            let browser = "all";

            switch(browser){
                case "firefox":
                    result.push(new T200Browser(browser));
                    break;
                case "chrome":
                    result.push(new T200Browser(browser));
                    break;
                case "all":
                    result.push(new T200Browser("firefox"));
                    break;
                case "none":
                    result.push(new T200Browser("firefox"));
                    result.push(new T200Browser("chrome"));
                    break;
            }
        }else{
            switch(browser){
                case "firefox":
                    result.push(new T200Browser(browser));
                    break;
                case "chrome":
                    result.push(new T200Browser(browser));
                    break;
                case "all":
                    result.push(new T200Browser("firefox"));
                    break;
                case "none":
                    result.push(new T200Browser("firefox"));
                    result.push(new T200Browser("chrome"));
                    break;
            }
        }

        return result;
    }

    run(source, method) {
        if(undefined == source){
            source = "";
            
            T200Path.is_dir(source).then(function(){

            }, function(){
                let obj = new T200Source();
    
                obj.run(source, method);
            });
        }else{
            T200Dir.is_dir(source).then(function(){

            }, function(){
                let obj = new T200Source();
    
                obj.run(source, method);
            });
        }
    }
}

module.exports = T200Browser;