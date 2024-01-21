const T200Actuator = require('./T200Actuator.js');
const T200Script = require('../script/T200Script.js');
const T200Sketch = require('../sketch/T200Sketch.js');


class T200Test {
    constructor() {

    }

    static create_script(category, project, source) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Script.create(category, project, source).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    static sketch(category, project, source, name) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            await T200Sketch.create(category, project, source, name).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }


    run(category, project, type, source, method, subdir) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            let actuator = new T200Actuator();

            await actuator.run(category, project, type, source, method, subdir).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }
}

module.exports = T200Test;