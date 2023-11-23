const { error, log } = require('../../library/T200Lib.js');
const T200Error = require('../../library/T200Error.js');


class T200HomeClear {
    constructor() {
        this.#load();
    }

    drop_house_rent() {
        return `drop table if exists house_rent`;
    }

    drop_house_wanted() {
        return `drop table if exists house_wanted`;
    }

    drop_job_recruit() {
        return `drop table if exists job_recruit`;
    }

    drop_job_wanted() {
        return `drop table if exists job_wanted`;
    }

    drop_trading_sell() {
        return `drop table if exists trading_sell`;
    }

    drop_trading_buy() {
        return `drop table if exists trading_buy`;
    }

    drop_exchange() {
        return `drop table if exists exchange`;
    }

    #load() {
        this.tables = [
            "person",
            "house_rent",
            "house_wanted",
            "region",
            "city",
            "index_cities"
        ];
    }

    drop_admin() {
        return `drop table if exists admin`;
    }

    drop_setting() {
        return `drop table if exists setting`;
    }

    drop_advert() {
        return `drop table if exists advert`;
    }

    drop_notice() {
        return `drop table if exists notice`;
    }
    
    drop_note() {
        return `drop table if exists note`;
    }

    drop_person() {
        return `drop table if exists person`;
    }

    drop_region() {
        return `drop table if exists region`;
    }

    drop_city() {
        return `drop table if exists city`;
    }

    drop_index_cities() {
        return `drop table if exists index_cities`;
    }

    clear(db) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            return db.execute(self.drop_person()).then(function(){
                log(__filename, "drop table person success");
            }, function(){
                log(__filename, "drop table person failure");
                return error();
            }).then(function(){
                return db.execute(self.drop_house_rent()).then(function(){
                    log(__filename, "drop table house rent success");
                }, function(){
                    log(__filename, "drop table house rent failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_house_wanted()).then(function(){
                    log(__filename, "drop table house wanted success");
                }, function(){
                    log(__filename, "drop table house wanted failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_job_recruit()).then(function(){
                    log(__filename, "drop table job recruit success");
                }, function(){
                    log(__filename, "drop table job recruit failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_job_wanted()).then(function(){
                    log(__filename, "drop table job wanted success");
                }, function(){
                    log(__filename, "drop table job wanted failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_trading_sell()).then(function(){
                    log(__filename, "drop table trading sell success");
                }, function(){
                    log(__filename, "drop table trading sell failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_trading_buy()).then(function(){
                    log(__filename, "drop table trading buy success");
                }, function(){
                    log(__filename, "drop table trading buy failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_exchange()).then(function(){
                    log(__filename, "drop table exchange success");
                }, function(){
                    log(__filename, "drop table exchange failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_admin()).then(function(){
                    log(__filename, "drop table admin success");
                }, function(){
                    log(__filename, "drop table admin failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_setting()).then(function(){
                    log(__filename, "drop table setting success");
                }, function(){
                    log(__filename, "drop table setting failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_advert()).then(function(){
                    log(__filename, "drop table advert success");
                }, function(){
                    log(__filename, "drop table advert failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_notice()).then(function(){
                    log(__filename, "drop table notice success");
                }, function(){
                    log(__filename, "drop table notice failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_note()).then(function(){
                    log(__filename, "drop table note success");
                }, function(){
                    log(__filename, "drop table note failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_region()).then(function(){
                    log(__filename, "drop table region success");
                }, function(){
                    log(__filename, "drop table region failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_city()).then(function(){
                    log(__filename, "drop table city success");
                }, function(){
                    log(__filename, "drop table city failure");
                    return error();
                });
            }, function(){
                return error();
            }).then(function(){
                return db.execute(self.drop_index_cities()).then(function(){
                    log(__filename, "drop table index_cities success");
                }, function(){
                    log(__filename, "drop table index_cities failure");
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

    clear_all(db) {
        let self = this;
        let promise = new Promise(function(resolve, reject){
            let result = false;

            try{
                self.tables.forEach(table => {
                    if(!result){
                        db.execute(`drop table if exists ${table}`).then(function(data){
                            if(data){
                                result = true;
                            }else{
                                result = false;
                            }
                        }, function(){
                            result = false;
                        });
                        if(!result){
                            return;
                        }                        
                    }
                });
            }catch(err){
                reject();            
            }
        
        });

        return promise;
    }
}

module.exports = T200HomeClear;