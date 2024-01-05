class T200Link {
    constructor() {

    }

    create(element) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.url = element.url;
            self.type = element.type;
            self.value = element.value;
            self.locate_type = element.locate_type;
            self.locate_value = element.locate_value;
            resolve();
        });

        return promise;
    }

    run(browser) {
        let self = this;
        let promise = new Promise(function(resolve, reject){

            resolve();
        });

        return promise;
    }
}

module.exports = T200Link;