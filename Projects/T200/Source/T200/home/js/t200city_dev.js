let cities_dev = new T200Vessel();
let regions_dev = new T200Vessel();
let countries_dev = new T200Vessel();
let continents_dev = new T200Vessel();
let home_dev = new T200Vessel();




let japan_dev = new T200Vessel([
    [10000,     'tokyo',                true,       '{"key":"tokyo","name":"Tokyo","continent":"asia","region":"japan"}'],
    [10001,     'osaka',                false,      '{"key":"osaka","name":"Osaka","continent":"asia","region":"japan"}'],
    [19999,     'japan_other',          false,      '{"key":"japan_other","name":"Other","continent":"asia","region":"japan"}']
]);

let south_korea_dev = new T200Vessel([
    [20000,     'seoul',                    true,       '{"key":"seoul","name":"Seoul","continent":"asia","region":"south korea"}'],
    [19999,     'south_korea_other',        false,       '{"key":"south_korea_other","name":"Other","continent":"asia","region":"south korea"}']
]);

let asia_other_dev = new T200Vessel();

let asia_dev = new T200Vessel([
    [1000,      'japan',            'Japan',            true,       japan_dev],
    [1001,      'south korea',      'South Korea',      true,       south_korea_dev],
    [1999,      'asia_other',       'Other',            false,      asia_other_dev]
]);

let earth_dev = new T200Vessel([
    [100,       'asia',         'Asia',         asia_dev]
]);


new T200ContinentLoader(cities_dev, regions_dev, countries_dev, continents_dev, home_dev, earth_dev);


function home_dev_init() {
    let result = "";
    
    home_dev.array().forEach(element => {
        let obj = JSON.parse(element.data);

        if(obj){
            result += `<a href="/region/city.html?id=${element.key}">${obj.name}</a>`;
        }
    });

    $.id('region_box').innerHTML = result;
}

function city_dev_setting(id) {
    let item = cities_dev.key(id);
    let result = "";

    if(item){
        let obj = JSON.parse(item.data);

        if(obj){
            let region = regions_dev.value(obj.region);

            if(region){
                result = `#<a href="/region/region.html?id=${region.key}">${region.name}</a> > <a href="/region/city.html?id=${item.key}">${obj.name}</a>`;
            }
        }
        
    }

    $.id("region_box").innerHTML = result;
}