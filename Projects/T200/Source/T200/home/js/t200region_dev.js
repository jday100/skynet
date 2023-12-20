let south_korea_dev = new T200Vessel([
    [20000,     'seoul'],
    [29999,     'other']
]);

let japan_dev = new T200Vessel([
    [10000,     'tokyo'],
    [10001,     'osaka'],
    [19999,     'other']
]);

let asia_dev = new T200Vessel([
    [1000,      'china'],
    [1001,      'japan',            japan_dev],
    [1002,      'south korea',      south_korea_dev],
    [1003,      'singapore'],
    [1004,      'other']
]);


let regions_dev = new T200Vessel();

let continents_dev = new T200Vessel([
    [100,       'asia',             asia_dev],
    [101,       'america'],
    [102,       'europe'],
    [103,       'oceania'],
    [104,       'africa'],
    [105,       'other']
]);


///home

let cities_list = [
    ['asia',            'south korea',              'seoul'],
    ['asia',            'japan',                    'tokyo']
];


///function
function continents_dev_init(obj, value) {
    let items = continents_dev;

    if(undefined == items){
        obj.innerHTML = "";
        obj.value = "";
    }else{
        let result = "";

        items.array().forEach(item => {
            if(value == item){
                result += `<option selected value='${item[0]}'>${item[1]}</option>`;
            }else{
                result += `<option value='${item[0]}'>${item[1]}</option>`;
            }
        });
        obj.innerHTML = result;
        obj.value = "";
    }
}


function continent_dev_change(obj, id) {
    let region = continents_dev.key(obj.value);

    if(undefined == region || undefined == region[2]){
        $.id(id).innerHTML = "";
        $.id(id).value = "";
    }else{
        let result = "";
        region[2].array().forEach(item => {
            result += `<option value='${item[0]}'>${item[1]}</option>`;
        });
        $.id(id).innerHTML = result;
        $.id(id).value = "";
    }
}


function region_dev_change(continent, region, id) {
    let regions = continents_dev.key($.id(continent).value);

    if(undefined == regions && undefined == regions[2]){
        $.id(id).innerHTML = "";
        $.id(id).value = "";
    }else{
        let cities = regions[2].key($.id(region).value);

        if(undefined == cities || undefined == cities[2]){
            $.id(id).innerHTML = "";
            $.id(id).value = "";
        }else{
            let result = "";
            cities[2].array().forEach(item => {
                result += `<option value='${item[0]}'>${item[1]}</option>`;
            });
            $.id(id).innerHTML = result;
            $.id(id).value = "";
        }
    }
}


function show_continent(source, target) {
    let value = $.id(source).value;
    let result = continents_dev.key(value);

    if(undefined == result){

    }else{
        $.id(target).value = result[1];
    }
}

function show_country(continent, source, target) {
    let obj = continents_dev.key($.id(continent).value);

    if(undefined == obj || undefined == obj[2]){

    }else{
        $.id(target).value = obj[2].key($.id(source).value)[1];
    }
}

function show_region(continent, source, target) {
    let obj = continents_dev.key($.id(continent).value);

    if(undefined == obj || undefined == obj[2]){

    }else{
        $.id(target).value = obj[2].key($.id(source).value)[1];
    }
}

function show_city(continent, region, source, target) {
    let cobj = continents_dev.key($.id(continent).value);

    if(undefined == cobj || undefined == cobj[2]){

    }else{
        let robj = cobj[2].key($.id(region).value);

        if(undefined == robj || undefined == robj[2]){

        }else{
            $.id(target).value = robj[2].key($.id(source).value)[1];
        }
    }
}


function region_dev_init() {
    let result = "";
    cities_list.forEach(item => {
        let continent = continents_dev.value(item[0]);

        if(undefined == continent){

        }else{
            let region = continent[2].value(item[1]);
            
            if(undefined == region){

            }else{
                let city = region[2].value(item[2]);

                if(undefined == city){

                }else{
                    result += `<a href="/region/city.html?id=${city[0]}">${item[2]}</a>`;
                }
            }
        }
    });

    $.id('region_box').innerHTML = result;   
}

function region_dev_setting(id) {
    let result = "";


    $.id('region_box').innerHTML = result;   
}

function city_dev_setting(id) {
    let result = "";


    $.id('region_box').innerHTML = result;   
}


function regions_setting() {
    let result = "";
    continents_dev.array().forEach(item => {
        result += merge_region_panel(item);
    });

    $.id('list_box').innerHTML = result;
}

function merge_region_panel(item) {
    let result = "";

    result += `
        <fieldset>
            <legend>${item[1]}</legend>
            <div>
        `;

    let obj = item[2];

    if(undefined == obj){

    }else{
        obj.array().forEach(region => {
            result += merge_region(region[0], region[1]);
        });
    }
    
    result += `    
            </div>
        </fieldset>
    `;

    return result;
}

function cities_setting(id) {
    let region = regions_dev.key(id);

    if(undefined == region){
        return;
    }
    let result = merge_city_panel(region);
    $.id('list_box').innerHTML = result;
}

function merge_city_panel(region) {
    let result = "";

    region.array().forEarch(item => {
        result += merge_city(item[0], item[1]);
    });

    return result;
}

function merge_region(id, name) {
    return `<a href='/region/regions.html?id=${id}'>${name}</a>`;
}

function merge_city(id, name) {
    return `<a href='/region/city.html?id=${id}'>${name}</a>`;
}