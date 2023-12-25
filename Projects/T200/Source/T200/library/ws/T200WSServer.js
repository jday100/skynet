class T200WSServer {
    constructor() {
        this.sockets = {};
    }

    append(key, req, res) {
        let obj = {};

        obj.req = req;
        obj.res = res;

        this.sockets[key] = obj;
    }

    get(key) {
        return this.sockets[key];
    }
}

module.exports = T200WSServer;