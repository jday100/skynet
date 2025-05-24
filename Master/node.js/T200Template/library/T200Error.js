class T200Error {
    constructor() {
        this.id = 0;
        this.msg = '';
    }

    static build() {
        return new T200Error();
    }
}

module.exports = T200Error;