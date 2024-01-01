class T200Register {
    constructor() {
        this.url = "/register";
    }

    run_register() {
        let self = this;

        self.get(self.url).then(function(){

        }, function(){

        });
    }

    get(url) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            self.browser.get("http://localhost:8888" + url);
        });

        return promise;
    }
}

module.exports = T200Register;