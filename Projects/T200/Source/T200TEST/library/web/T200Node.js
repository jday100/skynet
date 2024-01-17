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
}

module.exports = T200Node;