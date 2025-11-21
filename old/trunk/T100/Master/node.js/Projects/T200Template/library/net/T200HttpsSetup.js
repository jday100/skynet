class T200HttpsSetup {
    host = "localhost";
    port = 443;
    index = "index.html";
    home = "home";
    actions = "project/actions";
    pages = "project/pages";
    //
    cookie_live_time = 60 * 15;
    session_live_time = 60 * 15;

    constructor() {

    }
}

module.exports = T200HttpsSetup;