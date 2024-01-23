const HtmlParser = require('htmlparser2');


class T200HtmlParser {
    constructor() {

    }

    parse(html) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let handler = new HtmlParser.DefaultHandler(function(err, dom){

            });

            let parser = new HtmlParser.Parser(handler);

            parser.parseComplete(html);

            //let result = JSON.stringify(handler.dom);

            //console.log(result);

            let result = {};
            result.value = "";
            self.#traversal(handler.dom[0], result);

            let value = JSON.stringify(result, "", "\t");

            console.log(value);

            resolve(value);
        });

        return promise;
    }

    #traversal(node, result) {
        if('tag' == node.type){
            console.log(node.name);
            this.#done(node, result);

            if(undefined == node.children || 0 == node.children.lenght){

            }else{     
                result.children = new Array();          
                for(let child of node.children){
                    let item = {};
                    item.value = result.value;
                    this.#traversal(child, item);
                    result.children.push(item);
                }                
            }
        }else{
            console.log(node.name);
        }
    }

    #done(node, result) {
        result.value += node.name + " > ";
        switch(node.name){
            case 'a':
                this.#link(node, result);
                break;
            case 'div':
                this.#div(node, result);
                break;
            case 'form':
                this.#form(node, result);
                break;
            case 'input':
                this.#input(node, result);
                break;
            case 'nav':
                this.#nav(node, result);
                break;
            case 'text':
                this.#text(node, result);
                break;
            case 'password':
                this.#password(node, result);
                break;   
        }
    }

    #div(node, result) {
        result.type = "div";
        result.name = node.name;

        if(undefined == node.attribs["id"]){

        }else{
            result.id = node.attribs["id"];
        }

        if(undefined == node.attribs["class"]){

        }else{
            result.class = node.attribs["class"];
        }
    }

    #link(node, result) {
        result.type = "link";
        if(undefined == node.attribs["locale"]){
            
        }else{
            result.locate = new Array();
            
            let locate = {};

            locate.type = "css";
            locate.value = `${node.name}[locale=\"${node.attribs["locale"]}\"]`;

            result.locate.push(locate);
        }

        if(undefined == node.attribs["href"]){

        }else{
            result.url = node.attribs["href"];
        }

        if(undefined == node.attribs["target"]){

        }else{
            result.target = node.attribs["target"];
        }

        if(node.children && 1 == node.children.length){
            result.text = node.children[0].data;
        }
    }

    #form(node, result) {
        result.type = "form";
        result.name = node.name;
    }

    #input(node, result) {
        result.type = "input";

        result.locate = new Array();
        if(undefined == node.attribs["locale"]){
            
        }else{            
            let locate = {};

            locate.type = "css";
            locate.value = `${node.name}[locale=\"${node.attribs["locale"]}\"]`;

            result.locate.push(locate);
        }

        if(undefined == node.attribs["name"]){
            
        }else{            
            let locate = {};

            locate.type = "name";
            locate.value = node.attribs["name"];

            result.locate.push(locate);
        }
    }

    #nav(node, result) {
        result.type = "nav";
    }

    #text(node, result) {
        result.type = "text";
    }

    #password(node, result) {
        result.type = "password";
    }

}

module.exports = T200HtmlParser;