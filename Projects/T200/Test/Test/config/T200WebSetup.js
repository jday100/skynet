class T200WebSetup {
    constructor() {

    }

    static protocol = "http";
    static host = "localhost";
    static port = 8888;

    static url() {
        return `${T200WebSetup.protocol}://${T200WebSetup.host}:${T200WebSetup.port}`;
    }
}

module.exports = T200WebSetup;