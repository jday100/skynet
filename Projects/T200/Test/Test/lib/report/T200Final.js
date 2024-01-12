const { elementTextContains } = require("selenium-webdriver/lib/until");

class T200Final {
    constructor() {
        this.result = {};
    }

    append_project(name) {
        if(undefined == this.result.projects){
            this.result.projects = new Array();
        }

        let project = {};
        project.name = name;
        project.status = true;
        this.result.projects.push(project);
    }

    find_project(name) {
        if(undefined == this.result.projects){
            return undefined;
        }

        for(let project of this.result.projects){
            if(project.name == name){
                return project;
            }
        }
        return undefined;
    }

    append_page(project, page) {
        if(undefined == project.pages){
            project.pages = new Array();
        }

        let obj = {};
        obj.name = page.name;
        obj.status = true;
        project.pages.push(obj);
    }

    find_page(project, name) {
        let obj = this.find_project(project);

        if(obj){
            for(let page of obj.pages){
                if(page.name == name){
                    return page;
                }
            }
        }else{

        }
        return undefined;
    }

    append_entry(page, entry) {
        if(undefined == page.entries){
            page.entries = new Array();
        }

        let obj = {};
        obj.name = entry.name;
        obj.status = false;
        page.entries.push(obj);
    }

    find_entry(project, page, name) {
        let obj = this.find_page(project, page);

        if(obj){
            for(let entry of obj.entries){
                if(entry.name == name){
                    return entry;
                }
            }
        }else{

        }

        return undefined;
    }

    set_entry(project, page, name, value) {
        let entry = this.find_entry(project, page, name);

        if(entry){
            entry.status = value;
            return true;
        }
        return false;
    }

    set_failure(project, page, name) {
        if(undefined == this.result.projects){
            return false;
        }

        let obj;
        for(let item of this.result.projects){
            if(item.name == project){
                obj = item;
                break;
            }
        }

        if(undefined == obj || undefined == obj.pages){
            return false;
        }

        let value;
        for(let item of obj.pages){
            if(item.name == page){
                value = item;
                break;
            }
        }

        if(undefined == value || undefined == value.entries){
            return false;
        }

        for(let item of value.entries){
            if(item.name == name){
                item.status = false;
                value.status = false;
                obj.status = false;
                return true;
            }
        }

        return false;
    }
}

module.exports = T200Final;