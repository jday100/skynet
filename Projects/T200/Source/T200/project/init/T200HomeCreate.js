const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');


class T200HomeCreate {
    constructor() {

    }

   create_house_rent() {
        return "create table if not exists house_rent ( \
            id int primary key auto_increment, \
            user_id int, \
            status int not null default 0, \
            parent_id int default 0, \
            city_id int default 0,\
            title varchar(255), \
            content text, \
            create_time timestamp not null default current_timestamp, \
            fulltext (title, content) with parser ngram \
            ) character set utf8";
   }

    create_house_wanted() {
        return "create table if not exists house_wanted ( \
            id int primary key auto_increment, \
            user_id int, \
            status int not null default 0, \
            parent_id int default 0, \
            city_id int default 0,\
            title varchar(255), \
            content text, \
            create_time timestamp not null default current_timestamp, \
            fulltext (title, content) with parser ngram \
            ) character set utf8";
    }

    create_job_recruit() {
        return "create table if not exists job_recruit ( \
            id int primary key auto_increment, \
            user_id int, \
            status int not null default 0, \
            parent_id int default 0, \
            city_id int default 0,\
            title varchar(255), \
            content text, \
            create_time timestamp not null default current_timestamp, \
            fulltext (title, content) with parser ngram \
            ) character set utf8";
    }

    create_job_wanted() {
        return "create table if not exists job_wanted ( \
            id int primary key auto_increment, \
            user_id int, \
            status int not null default 0, \
            parent_id int default 0, \
            city_id int default 0,\
            title varchar(255), \
            content text, \
            create_time timestamp not null default current_timestamp, \
            fulltext (title, content) with parser ngram \
            ) character set utf8";
    }

    create_trading_sell() {
        return "create table if not exists trading_sell ( \
            id int primary key auto_increment, \
            user_id int, \
            status int not null default 0, \
            parent_id int default 0, \
            city_id int default 0,\
            title varchar(255), \
            content text, \
            create_time timestamp not null default current_timestamp, \
            fulltext (title, content) with parser ngram \
            ) character set utf8";
    }

    create_trading_buy() {
        return "create table if not exists trading_buy ( \
            id int primary key auto_increment, \
            user_id int, \
            status int not null default 0, \
            parent_id int default 0, \
            city_id int default 0,\
            title varchar(255), \
            content text, \
            create_time timestamp not null default current_timestamp, \
            fulltext (title, content) with parser ngram \
            ) character set utf8";
    }

    create_exchange() {
        return "create table if not exists exchange ( \
            id int primary key auto_increment, \
            user_id int, \
            status int not null default 0, \
            parent_id int default 0, \
            title varchar(255), \
            content text, \
            create_time timestamp not null default current_timestamp, \
            fulltext (title, content) with parser ngram \
            ) character set utf8";
    }

    ///
    create_admin() {
        return `create table if not exists admin ( \
            id int primary key auto_increment, \
            user_id int default 0 UNIQUE, \
            status int not null default 0, \
            remark text, \
            permission text, \
            create_time timestamp not null default current_timestamp \
            ) character set utf8`;
    }

    create_setting() {
        return `create table if not exists setting ( \
            id int primary key auto_increment, \
            setting_id int default 0 UNIQUE, \
            status int not null default 0, \
            name varchar(255), \
            content text, \
            modify_time timestamp not null default current_timestamp \
            ) character set utf8`;
    }

    create_person() {
        return `create table if not exists person ( \
            user_id int primary key auto_increment, \
            city_id int default 0, \
            status int not null default 0, \
            username varchar(50) UNIQUE, \
            password varchar(100), \
            email varchar(100) UNIQUE, \
            create_time timestamp not null default current_timestamp \
            ) character set utf8`;
    }

    create_advert() {
        return `create table if not exists advert ( \
            id int primary key auto_increment, \
            status int not null default 0, \
            name varchar(255), \
            create_time timestamp not null default current_timestamp \
            ) character set utf8`;
    }

    create_notice() {
        return "create table if not exists notice ( \
            id int primary key auto_increment, \
            user_id int, \
            status int not null default 0, \
            title varchar(255), \
            content text, \
            create_time timestamp not null default current_timestamp, \
            fulltext (title, content) with parser ngram \
            ) character set utf8";
    }

    create_note() {
        return `create table if not exists note ( \
            id int primary key auto_increment, \
            user_id int, \
            status int not null default 0, \
            title varchar(255), \
            content text, \
            create_time timestamp not null default current_timestamp, \
            fulltext (title, content) with parser ngram \
            ) character set utf8`;
    }

    create_region() {
        return `create table if not exists region ( \
            id int primary key auto_increment, \
            name varchar(255), \
            content text \
            ) character set utf8`;
    }

    create_city() {
        return `create table if not exists city ( \
            id int primary key auto_increment, \
            region_id int, \
            level int, \
            name varchar(255), \
            content text \
            ) character set utf8`;
    }

    create_index_cities() {
        return `create table if not exists index_cities ( \
            id int primary key auto_increment, \
            city_id int, \
            level int, \
            intro varchar(255) \
            ) character set utf8`;
    }

    create(db) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return db.execute(self.create_person()).then(function(){
                log(__filename, "create table person success");
            }, function(){
                log(__filename, "create table person failure");
                return error();
            }).then(function(){
                return db.execute(self.create_house_rent()).then(function(){
                    log(__filename, "create table house rent success");
                }, function(){
                    log(__filename, "create table house rent failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_house_wanted()).then(function(){
                    log(__filename, "create table house wanted success");
                }, function(){
                    log(__filename, "create table house wanted failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_job_recruit()).then(function(){
                    log(__filename, "create table job recruit success");
                }, function(){
                    log(__filename, "create table job recruit failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_job_wanted()).then(function(){
                    log(__filename, "create table job wanted success");
                }, function(){
                    log(__filename, "create table job wanted failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_trading_sell()).then(function(){
                    log(__filename, "create table trading sell success");
                }, function(){
                    log(__filename, "create table trading sell failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_trading_buy()).then(function(){
                    log(__filename, "create table trading buy success");
                }, function(){
                    log(__filename, "create table trading buy failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_exchange()).then(function(){
                    log(__filename, "create table exchange success");
                }, function(){
                    log(__filename, "create table exchange failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_admin()).then(function(){
                    log(__filename, "create table admin success");
                }, function(){
                    log(__filename, "create table admin failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_setting()).then(function(){
                    log(__filename, "create table setting success");
                }, function(){
                    log(__filename, "create table setting failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_advert()).then(function(){
                    log(__filename, "create table advert success");
                }, function(){
                    log(__filename, "create table advert failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_notice()).then(function(){
                    log(__filename, "create table notice success");
                }, function(){
                    log(__filename, "create table notice failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_note()).then(function(){
                    log(__filename, "create table note success");
                }, function(){
                    log(__filename, "create table note failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_region()).then(function(){
                    log(__filename, "create table region success");
                }, function(){
                    log(__filename, "create table region failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_city()).then(function(){
                    log(__filename, "create table city success");
                }, function(){
                    log(__filename, "create table city failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.create_index_cities()).then(function(){
                    log(__filename, "create table index_cities success");
                }, function(){
                    log(__filename, "create table index_cities failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                resolve();
            }, function(){
                reject();
                return error();
            });
        });

        return promise;
    }
}

module.exports = T200HomeCreate;