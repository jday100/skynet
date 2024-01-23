class T200Options {
    constructor() {

    }

    static form(item) {
        let result = {};

        result.unit = "form";
        result.page = "form";
        result.form = "form";
        result.step = item;

        return result;
    }

    static verify(item) {
        let result = {};

        result.unit = item.verify.unit;
        result.page = item.verify.page;
        result.module = item.verify.module;
        result.form = item.verify.form;
        result.step = item;

        return result;
    }
}

module.exports = T200Options;