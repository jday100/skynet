class T200Report {
    constructor() {

    }

    report() {
        if(undefined == global.final.result.projects){
            return;
        }

        for(let project of global.final.result.projects){
            this.#print_project(project);
        }
    }

    #print_project(project) {
        console.log(`Project : ${project.name}`);

        if(undefined == project.pages){
            return;
        }

        for(let page of project.pages){
            this.#print_page(page);
        }
    }

    #print_page(page) {
        let status = page.status ? "pass" : "error";
        console.log(`\tPage : ${page.name}\t${status}`);

        if(undefined == page.entries){
            return;
        }

        for(let entry of page.entries){
            this.#print_entry(entry);
        }
    }

    
    #print_entry(entry) {
        let status = entry.status ? "pass" : "error";
        console.log(`\t\tEntry : ${entry.name}\t${status}`);
    }
}

module.exports = T200Report;