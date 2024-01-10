class T200WSServer {
    constructor() {
        this.sockets = {};
    }

    append(obj) {
        this.sockets[obj.id] = obj;
    }

    get(key) {
        return this.sockets[key];
    }
}

module.exports = T200WSServer;