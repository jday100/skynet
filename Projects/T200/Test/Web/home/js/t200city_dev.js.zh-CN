let cities_dev = new T200Vessel();
let regions_dev = new T200Vessel();
let countries_dev = new T200Vessel();
let continents_dev = new T200Vessel();
let home_dev = new T200Vessel();


/// Asia
//10000 ~ 20000
let china_dev = new T200Vessel();

//20000 ~ 30000
let japan_dev = new T200Vessel([
    [20000,     'tokyo',                true,       '{"key":"tokyo","name":"Tokyo","continent":"asia","region":"japan"}'],
    [20001,     'osaka',                false,      '{"key":"osaka","name":"Osaka","continent":"asia","region":"japan"}'],
    [29999,     'japan_other',          false,      '{"key":"japan_other","name":"Other","continent":"asia","region":"japan"}']
]);

//30000 ~ 40000
let south_korea_dev = new T200Vessel([
    [30000,     'seoul',                    true,       '{"key":"seoul","name":"Seoul","continent":"asia","region":"south korea"}'],
    [39999,     'south_korea_other',        false,       '{"key":"south_korea_other","name":"Other","continent":"asia","region":"south korea"}']
]);

let asia_other_dev = new T200Vessel();

//1000 ~ 2000
let asia_dev = new T200Vessel([
    [1001,      'japan',            'Japan',            true,       japan_dev],
    [1002,      'south korea',      'South Korea',      true,       south_korea_dev],
    [1999,      'asia_other',       'Other',            false,      asia_other_dev]
]);

/// Asia

/// America
//2000 ~ 3000
let america_dev = new T200Vessel([
    //[2000,      '',                 '',                 true,       ],
    //[2999,      'america_other',    'Other',            false,      america_other_dev]
]);


/// Europe
//3000 ~ 4000
let europe_dev = new T200Vessel();

/// Europe

/// Oceania
//4000 ~ 5000
let oceania_dev = new T200Vessel();

/// Oceania

/// Africa
//5000 ~ 6000
let africa_dev = new T200Vessel();

/// Africa

/// Other
//9000 ~ 10000
let continent_other_dev = new T200Vessel();

/// Other

/// Earth
//100 ~ 200
let earth_dev = new T200Vessel([
    [100,       'asia',                 'Asia',             asia_dev],
    [101,       'america',              'America',          america_dev],
    [102,       'europe',               'Europe',           europe_dev],
    [103,       'oceania',              'Oceania',          oceania_dev],
    [104,       'africa',               'Africa',           africa_dev],
    [199,       'continent_other',      'Other',            continent_other_dev]
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

function region_dev_setting(id) {
    let region = regions_dev.key(id);
    let result = "";

    if(region){
        result = `#<a href="/region/region.html?id=${region.key}">${region.name}</a>`;
    }

    $.id("region_box").innerHTML = result;
}

function continents_dev_init(obj, value) {
    let items = continents_dev;

    if(undefined == items){
        obj.innerHTML = "";
        obj.value = "";
    }else{
        let result = "";

        items.array().forEach(item => {
            if(value == item.key){
                result += `<option selected value='${item.key}'>${item.name}</option>`;
            }else{
                result += `<option value='${item.key}'>${item.name}</option>`;
            }
        });
        obj.innerHTML = result;
        obj.value = "";
    }
}

function continent_dev_change(obj, id) {
    let region = continents_dev.key(obj.value);

    if(undefined == region){
        $.id(id).innerHTML = "";
        $.id(id).value = "";
        $.id("continent_title").value = "";
    }else{
        let result = "";
        region.data.array().forEach(item => {
            result += `<option value='${item[0]}'>${item[2]}</option>`;
        });
        $.id("continent_title").value = obj.options[obj.selectedIndex].text;
        $.id(id).innerHTML = result;
        $.id(id).value = "";
    }
}

function country_dev_change(obj, id) {
    if(undefined == obj){

    }else{
        $.id(id).value = obj.options[obj.selectedIndex].text;
    }
}

function region_dev_change(region, id) {
    let obj = regions_dev.key($.id(region).value);

    if(undefined == obj){
        $.id(id).innerHTML = "";
        $.id(id).value = "";
        $.id("region_title").value = "";
    }else{
        let result = "";
        obj.data.array().forEach(item => {
            if(undefined == item){
                
            }else{
                let value = JSON.parse(item[3]);

                if(undefined == value){

                }else{
                    result += `<option value='${item[0]}'>${value.name}</option>`;
                }
            }
        });
        $.id("region_title").value = $.id("region").options[$.id("region").selectedIndex].text;
        $.id(id).innerHTML = result;
        $.id(id).value = "";
    }
}

function city_dev_change(obj, id) {
    if(undefined == obj){

    }else{
        $.id(id).value = obj.options[obj.selectedIndex].text;
    }
}

function show_continent(source, target) {
    let value = $.id(source).value;
    let result = continents_dev.key(value);

    if(undefined == result){

    }else{
        $.id(target).value = result.name;
    }
}


function show_country(source, target) {
    let obj = countries_dev.key($.id(source).value);

    if(undefined == obj){

    }else{
        $.id(target).value = obj.name;
    }
}

function show_region(source, target) {
    let obj = regions_dev.key($.id(source).value);

    if(undefined == obj){

    }else{
        $.id(target).value = obj.name;
    }
}

function show_city(source, target) {
    let city = cities_dev.key($.id(source).value);

    if(undefined == city){

    }else{
        let obj = JSON.parse(city.data);

        if(undefined == obj){

        }else{
            $.id(target).value = obj.name;
        }
    }
}