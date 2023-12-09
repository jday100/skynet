let continents_hash = {};
let continents_list = {};

continents_list = ['asia', 'america', 'europe', 'oceania', 'africa', 'other'];

let asia = {};
let america = {};
let europe = {};
let africa = {};
let continent_other = {};


continents_hash['asia']             = asia;
continents_hash['america']          = america;
continents_hash['europe']           = europe;
continents_hash['oceania']          = oceania;
continents_hash['africa']           = africa;
continents_hash['other']            = continent_other;

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
let cities_hash = {};

//japan
//10000~20000
cities_hash[10000]         = ['asia', 'japan', 'tokyo'];
cities_hash[10001]         = ['asia', 'japan', 'osaka'];
cities_hash[19999]         = ['asia', 'japan', 'other'];

//south korea
//20000~30000
cities_hash[20000]         = ['asia', 'south korea', 'seoul'];
cities_hash[29999]         = ['asia', 'south korea', 'other'];


//home
let cities_list = [
    ['South Korea',         'Seoul',        'seoul'],
    ['Japan',               'Tokyo',        'tokyo']
];


///function
function continents_init(obj, value) {
    let items = continents_list;

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


function region_setting() {
    let result = "";
    cities_list.forEach(item => {
        let region = cities_hash[item[2]];

        if(region){
            let city = region[item[1]];

            if(city){
                //for(let i=0;i<20;i++)
                result += `<a href="/region/city.html?id=${city}">${item[1]}</a>`;
            }else{
                alert('Load Error');
            }
        }else{
            alert('Load Error');
        }
    });

    $.id('region_box').innerHTML = result;    
}