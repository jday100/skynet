const HtmlParser = require('htmlparser');


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

            let result = JSON.stringify(handler.dom);

            console.log(result);
        });

        return promise;
    }
}

module.exports = T200HtmlParser;