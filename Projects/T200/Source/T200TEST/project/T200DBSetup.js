class T200DBSetup {
    constructor() {
        this.type = "mariadb";
        this.host = "localhost";
        this.port = 3306;
        this.database = "home";
        this.user = "home";
        this.password = "home123";
        this.charset = "utf8";
    }
}

module.exports = T200DBSetup;