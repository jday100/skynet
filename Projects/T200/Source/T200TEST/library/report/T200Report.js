class T200Report {
    constructor() {

    }

    report() {
        if(undefined == global.final.result.projects){
            return;
        }

        for(let project of global.final.result.projects.array()){
            this.#print_project(project);
        }
    }

    #print_project(project) {
        let status = project.status ? "pass" : "error";
        console.log(`Project : ${project.name}\t\t\t\t${status}`);

        if(undefined == project.values){
            return;
        }

        for(let page of project.values.array()){
            this.#print_page(page);
        }
    }

    #print_page(page) {
        let status = page.status ? "pass" : "error";
        console.log(`\tPage : ${page.name}\t\t${status}`);

        if(undefined == page.values){
            return;
        }

        for(let entry of page.values.array()){
            this.#print_entry(entry);
        }
    }

    #print_entry(entry) {
        let status = entry.status ? "pass" : "error";
        console.log(`\t\tEntry : ${entry.name}\t\t${status}`);
    }
}

module.exports = T200Report;