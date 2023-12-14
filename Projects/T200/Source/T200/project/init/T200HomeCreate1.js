const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');


class T200HomeCreate {
    constructor() {

    }

    merge_house_rent_sql() {
        return `
            create table if not exists house_rent (
                id int primary key auto_increment,
                user_id int,
                identity_id int,
                status int not null default 0,
                parent_type int default 0,
                parent_id int default 0,
                type_long int default 0,
                type_short int default 0,
                continent_id int default 0,
                continet_name varchar(100),
                region_id int default 0,
                region_name varchar(100),
                city_id int default 0,
                city_name varchar(100),
                title varchar(255),
                content text,
                create_time datetime not null default current_timestamp,
                modify_time timestamp not null default current_timestamp,
                INDEX(user_id),
                INDEX(identity_id),
                INDEX(parent_type),
                INDEX(parent_id),
                INDEX(continent_id),
                INDEX(region_id),
                INDEX(city_id),
                INDEX(status),
                INDEX(type_long),
                INDEX(type_short),
                fulltext (title, content) with parser ngram
            ) character set utf8
        `;
    }

    merge_house_wanted_sql() {
        return `
            create table if not exists house_wanted (
                id int primary key auto_increment,
                user_id int,
                identity_id int,
                status int not null default 0,
                parent_type int default 0,
                parent_id int default 0,
                type_long int default 0,
                type_short int default 0,
                continent_id int default 0,
                continet_name varchar(100),
                region_id int default 0,
                region_name varchar(100),
                city_id int default 0,
                city_name varchar(100),
                title varchar(255),
                content text,
                create_time datetime not null default current_timestamp,
                modify_time timestamp not null default current_timestamp,
                INDEX(user_id),
                INDEX(identity_id),
                INDEX(parent_type),
                INDEX(parent_id),
                INDEX(continent_id),
                INDEX(region_id),
                INDEX(city_id),
                INDEX(status),
                INDEX(type_long),
                INDEX(type_short),
                fulltext (title, content) with parser ngram
            ) character set utf8
        `;
    }

    merge_job_recruit_sql() {
        return `
            create table if not exists job_recruit (
                id int primary key auto_increment,
                user_id int,
                identity_id int,
                status int not null default 0,
                parent_type int default 0,
                parent_id int default 0,
                type_full int default 0,
                type_part int default 0,
                continent_id int default 0,
                continet_name varchar(100),
                region_id int default 0,
                region_name varchar(100),
                city_id int default 0,
                city_name varchar(100),
                title varchar(255),
                content text,
                create_time datetime not null default current_timestamp,
                modify_time timestamp not null default current_timestamp,
                INDEX(user_id),
                INDEX(identity_id),
                INDEX(parent_type),
                INDEX(parent_id),
                INDEX(continent_id),
                INDEX(region_id),
                INDEX(city_id),
                INDEX(status),
                INDEX(type_full),
                INDEX(type_part),
                fulltext (title, content) with parser ngram
            ) character set utf8
        `;
    }

    merge_job_wanted_sql() {
        return `
            create table if not exists job_wanted (
                id int primary key auto_increment,
                user_id int,
                identity_id int,
                status int not null default 0,
                parent_type int default 0,
                parent_id int default 0,
                type_full int default 0,
                type_part int default 0,
                continent_id int default 0,
                continet_name varchar(100),
                region_id int default 0,
                region_name varchar(100),
                city_id int default 0,
                city_name varchar(100),
                title varchar(255),
                content text,
                create_time datetime not null default current_timestamp,
                modify_time timestamp not null default current_timestamp,
                INDEX(user_id),
                INDEX(identity_id),
                INDEX(parent_type),
                INDEX(parent_id),
                INDEX(continent_id),
                INDEX(region_id),
                INDEX(city_id),
                INDEX(status),
                INDEX(type_full),
                INDEX(type_part),
                fulltext (title, content) with parser ngram
            ) character set utf8
        `;
    }

    merge_trading_sell_sql() {
        return `
            create table if not exists trading_sell (
                id int primary key auto_increment,
                user_id int,
                identity_id int,
                status int not null default 0,
                parent_type int default 0,
                parent_id int default 0,
                continent_id int default 0,
                continet_name varchar(100),
                region_id int default 0,
                region_name varchar(100),
                city_id int default 0,
                city_name varchar(100),
                title varchar(255),
                content text,
                create_time datetime not null default current_timestamp,
                modify_time timestamp not null default current_timestamp,
                INDEX(user_id),
                INDEX(identity_id),
                INDEX(parent_type),
                INDEX(parent_id),
                INDEX(continent_id),
                INDEX(region_id),
                INDEX(city_id),
                INDEX(status),
                fulltext (title, content) with parser ngram
            ) character set utf8
        `;
    }

    merge_trading_buy_sql() {
        return `
            create table if not exists trading_buy (
                id int primary key auto_increment,
                user_id int,
                identity_id int,
                status int not null default 0,
                parent_type int default 0,
                parent_id int default 0,
                continent_id int default 0,
                continet_name varchar(100),
                region_id int default 0,
                region_name varchar(100),
                city_id int default 0,
                city_name varchar(100),
                title varchar(255),
                content text,
                create_time datetime not null default current_timestamp,
                modify_time timestamp not null default current_timestamp,
                INDEX(user_id),
                INDEX(identity_id),
                INDEX(parent_type),
                INDEX(parent_id),
                INDEX(continent_id),
                INDEX(region_id),
                INDEX(city_id),
                INDEX(status),
                fulltext (title, content) with parser ngram
            ) character set utf8
        `;
    }

    merge_exchange_sql() {
        return `
            create table if not exists exchange (
                id int primary key auto_increment,
                user_id int,
                identity_id int,
                status int not null default 0,
                parent_type int default 0,
                parent_id int default 0,
                continent_id int default 0,
                continet_name varchar(100),
                region_id int default 0,
                region_name varchar(100),
                city_id int default 0,
                city_name varchar(100),
                title varchar(255),
                content text,
                create_time datetime not null default current_timestamp,
                modify_time timestamp not null default current_timestamp,
                INDEX(user_id),
                INDEX(identity_id),
                INDEX(parent_type),
                INDEX(parent_id),
                INDEX(continent_id),
                INDEX(region_id),
                INDEX(city_id),
                INDEX(status),
                fulltext (title, content) with parser ngram
            ) character set utf8
        `;
    }

    ///
    merge_admin_sql() {
        return `
            create table if not exists admin (
                id int primary key auto_increment,
                user_id int default 0 UNIQUE,
                status int not null default 0,
                remark text,
                permission text,
                create_time timestamp not null default current_timestamp
            ) character set utf8
        `;
    }

    merge_setting_sql() {
        return `
            create table if not exists setting (
                id int primary key auto_increment,
                setting_id int default 0 UNIQUE,
                status int not null default 0,
                name varchar(255),
                content text,
                modify_time timestamp not null default current_timestamp
            ) character set utf8
        `;
    }

    merge_person_sql() {
        return `
            create table if not exists person (
                user_id int primary key auto_increment,
                status int not null default 0,
                continent_id int default 0,
                continent_name varchar(100),
                country_id int default 0,
                country_name varchar(100),
                username varchar(50) UNIQUE,
                identity_id int not null default 0,
                password varchar(100),
                email varchar(100) UNIQUE,
                gender int not null default 0,
                year int,
                month int,
                day int,
                intro varchar(255),
                flag int not null default 0,
                create_time datetime not null default current_timestamp,
                modify_time timestamp not null default current_timestamp,
                login_time datetime,
                ip varchar(20),
                INDEX (ip)
            ) character set utf8
        `;
    }

    merge_identity_sql() {
        return `
            create table if not exists identity (
                identity_id int primary key auto_increment,
                user_id int not null default 0,
                status int not null default 0,
                nickname varchar(100),
                continent_id int default 0,
                continent_name varchar(100),
                region_id int default 0,
                region_name varchar(100),
                city_id int default 0,
                city_name varchar(100),
                intro varchar(255),
                ip varchar(20),
                create_time datetime not null default current_timestamp,
                modify_time timestamp not null default current_timestamp,
                fulltext (nickname) with parser ngram 
            ) character set utf8
        `;
    }

    merge_invitation_sql() {
        return `
            create table if not exists invitation (
                id int primary key auto_increment,
                user_id int,
                status int not null default 0,
                invite int not null default 0,
                create_time datetime not null default current_timestamp,
                using_time datetime,
                expiry_time datetime,
                INDEX(user_id),
                INDEX(status)
            ) character set utf8
        `;
    }

    merge_advert_sql() {
        return `
            create table if not exists advert (
                id int primary key auto_increment,
                status int not null default 0,
                name varchar(255),
                content text,
                create_time timestamp not null default current_timestamp
            ) character set utf8
        `;
    }

    merge_notice_sql() {
        return `
            create table if not exists notice (
                id int primary key auto_increment,
                user_id int,
                status int not null default 0,
                title varchar(255),
                content text,
                create_time timestamp not null default current_timestamp,
                fulltext (title, content) with parser ngram
            ) character set utf8
        `;
    }

    merge_note_sql() {
        return `
            create table if not exists note (
                id int primary key auto_increment,
                user_id int,
                status int not null default 0,
                title varchar(255),
                content text,
                create_time timestamp not null default current_timestamp,
                fulltext (title, content) with parser ngram
            ) character set utf8
        `;
    }

    merge_continent_sql() {
        return `
            create table if not exists continent (
                id int primary key auto_increment,
                name varchar(100),
                content varchar(255)
            ) character set utf8
        `;
    }

    merge_region_sql() {
        return `
            create table if not exists region (
                id int primary key auto_increment,
                name varchar(100),
                content varchar(255)
            ) character set utf8
        `;
    }

    merge_city_sql() {
        return `
            create table if not exists city (
                id int primary key auto_increment,
                region_id int not null default 0,
                name varchar(100),
                content varchar(255)
            ) character set utf8
        `;
    }



    create_house_rent(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_house_rent_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });
        });

        return promise;
    }

    create_house_wanted(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_house_wanted_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_job_recruit(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_job_recruit_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_job_wanted(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_job_wanted_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_trading_sell(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_trading_sell_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_trading_buy(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_trading_buy_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_exchange(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_exchange_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_admin(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_admin_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_setting(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_setting_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_person(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_person_sql();

            client.execute(sql).then(function(){
            
            }, function(err){
                return error();
            }).then(function(){
                sql = `insert into person (status, username, password, email)
                        values(1, 'admin', '1', 'admin@admin.com')`;
                return client.execute(sql);
            }, function(){
                return error();
            }).then(function(){
                resolve();
            }, function(){
                reject();
            });

        });

        return promise;
    }

    create_identity(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_identity_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_invitation(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_invitation_sql();

            client.execute(sql).then(function(){
            
            }, function(err){
                return error();
            }).then(function(){
                sql = `insert into invitation (user_id, status, invite, using_time, expiry_time) 
                        values(1, 1, 111111, current_timestamp, current_timestamp)`;
                return client.execute(sql);            
            }, function(){
                return error();
            }).then(function(){
                resolve();
            }, function(){
                reject();
            });

        });

        return promise;
    }

    create_advert(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_advert_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_notice(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_notice_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_note(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_note_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_continent(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_continent_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }

    create_region(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_region_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }


    create_city(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let sql = self.merge_city_sql();

            client.execute(sql).then(function(){
                resolve();
            }, function(err){
                reject();
            });

        });

        return promise;
    }



    async create(client) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            
            self.create_house_rent(client).then(function(){

            }, function(err){
                return error();
            }).then(function(){
                return self.create_house_wanted(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_job_recruit(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_job_wanted(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_trading_sell(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_trading_buy(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_exchange(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_admin(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_setting(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_person(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_identity(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_invitation(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_advert(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_notice(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_note(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_continent(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_region(client);
            }, function(){
                return error();
            }).then(function(){
                return self.create_city(client);
            }, function(){
                return error();
            }).then(function(){
                resolve();
            }, function(){
                reject();
            });

        });

        return promise;
    }
}

module.exports = T200HomeCreate;