const { Select } = require("selenium-webdriver");


class T200Node {
    constructor(node) {
        this.node = node;
    }

    click() {
        return this.node.click();
    }

    input(data) {
        return this.node.sendKeys(data);
    }

    select(name) {
        let obj = new Select(this.node);

        return obj.selectByValue(name);
    }
}

module.exports = T200Node;