//1~10000
let china = {};

//10000~20000
let japan = {};
japan['tokyo']                      = 10000;
japan['osaka']                      = 10001;
japan['other']                      = 19999;

//20000~30000
let south_korea = {};
south_korea['seoul']                = 20000;
south_korea['other']                = 29999;



//city
let city = {};

//japan
//10000~20000
city[10000]         = ['asia', 'japan', 'tokyo'];
city[10001]         = ['asia', 'japan', 'osaka'];
city[19999]         = ['asia', 'japan', 'other'];

//south korea
//20000~30000
city[20000]         = ['asia', 'south korea', 'seoul'];
city[29999]         = ['asia', 'south korea', 'other'];



//continents
let continents = {};

continents = ['asia', 'america', 'europe', 'oceania', 'africa', 'other'];

//regions
let regions = {};

regions['asia'] = [
    'south korea',
    'japan',
    'china',
    'singapore',
    'other'
];

regions['america'] = [
    'usa',
    'canada',
    'other'
];

regions['europe'] = [
    'united kingdom',
    'france',
    'german',
    'italy',
    'russia',
    'other'
];

regions['oceania'] = [
    'other'
];

regions['africa'] = [
    'other'
];

regions['other'] = [
    'other'
];


//cities
let cities = {};


cities['china']                 = china;
cities['japan']                 = japan;
cities['south korea']           = south_korea;




///function

function continent_init(obj, value) {
    let items = continents;

    if(undefined == items){
        
    }else{
        let result = "";

        items.forEach(item => {
            if(value == item){
                result += `<option selected value='${item}'>${item}</option>`;
            }else{
                result += `<option value='${item}'>${item}</option>`;
            }
        });
        obj.innerHTML = result;
        obj.value = "";
    }
}

function continent_change(value) {
    let items = regions[value];

    if(undefined == items){

    }else{
        let result = "";
        items.forEach(item => {
            result += `<option value='${item}'>${item}</option>`;
        });
        $.id('region').innerHTML = result;
        $.id('region').value = "";
    }
}


function region_change(value) {
    let items = cities[value];

    if(undefined == items){

    }else{
        let result = "";

        for(let item in items){
            result += `<option value='${items[item]}'>${item}</option>`;
        }
        $.id('city').innerHTML = result;
    }
}