class T200Element {
    constructor(element) {
        this.element = element;
    }

    click() {
        return this.element.click();
    }

    input(data) {
        return this.element.sendKeys(data);
    }
}

module.exports = T200Element;