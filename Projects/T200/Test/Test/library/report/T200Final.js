const T200Vessel = require('../T200Vessel.js');
const T200Entry = require('./T200Entry.js');


class T200Final {
    constructor() {
        this.result = {};
        this.result.projects = new T200Vessel();
    }

    append_project(name) {
        let entry = new T200Entry(name);
        entry.status = true;
        this.result.projects.append(name, name, entry);
    }

    project(name) {
        return this.result.projects.key(name);
    }

    append_page(project, name) {
        let value = this.result.projects.key(project);

        if(value){
            let entry = new T200Entry(name);
            entry.status = true;
            value.values.append(name, name, entry);
        }
    }

    page(project, name) {
        let value = this.result.projects.key(project);

        if(value){
            return value.values.key(name);
        }

        return;
    }

    append_entry(project, page, name) {
        let element = this.result.projects.key(project);

        if(element){
            let item = element.values.key(page);

            if(item){
                item.values.append(name, name, new T200Entry(name));
            }
        }
    }

    entry(project, page, name) {
        let element = this.result.projects.key(project);

        if(element){
            let item = element.values.key(page);

            if(item){
                return item.values.key(name);
            }
        }
        return;
    }

    entry_success(project, page, name) {
        let entry = this.entry(project, page, name);

        if(entry){
            entry.status = true;
        }
    }

    entry_failure(project, page, name) {
        let element = this.result.projects.key(project);

        if(element){
            let item = element.values.key(page);

            if(item){
                let entry = item.values.key(name);

                if(entry){
                    entry.status = false;
                    item.status = false;
                    element.status = false;
                }
            }
        }
    }
}

module.exports = T200Final;