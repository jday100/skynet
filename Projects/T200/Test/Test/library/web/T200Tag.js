class T200Tag {
    constructor() {

    }

    create(field) {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            self.field = field;
            self.name = field.name;
            resolve();
        });

        return promise;
    }

    create_entry() {
        let self = this;
        let promise = new Promise(async function(resolve, reject){
            global.final.append_entry(self.project, self.page, self.field.name);
            resolve();
        });

        return promise;
    }
}

module.exports = T200Tag;