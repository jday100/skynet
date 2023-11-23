const { error, log } = require('../../T200Lib.js');
const T200Error = require('../../T200Error.js');

const T200EJS = require('../../template/T200EJS.js');


class T200ViewBase {
    constructor(resource) {
        this.resource = resource;
        this.render = new T200EJS();
    }

    render_file(file, data) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let real = self.resource.merge_pages(file);
            self.render.render_file(real, data).then(resolve, reject);
        });

        return promise;
    }
}

module.exports = T200ViewBase;