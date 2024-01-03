const T200Web = require('../../lib/web/T200Web.js');


class T200RegisterWeb extends T200Web {
    constructor() {
        let objects = [
            'nav',
            'person'
        ];

        let fields = [
            {
                "name"  : "username",
                "field" : "username"
            },{
                "name"  : "password",
                "field" : "password"
            },{
                "name"  : "password",
                "field" : "password"
            },{
                "name"  : "email",
                "field" : "email"
            },{
                "name"  : "auth",
                "type"  : "fixed",
                "field" : "auth"
            },{
                "name"  : "invite",
                "field" : "invite"
            }
        ];

        /*
        let fields = [
            {
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "status",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "nickname",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            },{
                "name"  : "user_id",
                "hidden"    : true
            }
        ];
        */

        super(objects, fields);
    }
}

module.exports = T200RegisterWeb;