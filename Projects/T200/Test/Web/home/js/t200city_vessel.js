class T200CityLoader {
    constructor(citis_dev, home_dev, data) {
        this.#load(citis_dev, home_dev, data);
    }

    #load(citis_dev, home_dev, data) {
        data.array().forEach(element => {
            let obj = {};

            obj.key= element[0];
            obj.value = element[1];
            obj.data = element[3];

            if(element[2]){                
                home_dev.append(obj.key, obj.value, obj);
            }

            citis_dev.append(obj.key, obj.value, obj);
        });
    }
}

class T200RegionLoader {
    constructor(cities_dev, regions_dev, countries_dev, home_dev, data) {
        this.#load(cities_dev, regions_dev, countries_dev, home_dev, data);
    }

    #load(cities_dev, regions_dev, countries_dev, home_dev, data) {
        data.array().forEach(element => {
            let obj = {};

            obj.key = element[0];
            obj.value = element[1];
            obj.name = element[2];
            obj.data = element[4];

            if(element[3]){
                countries_dev.append(obj.key, obj.value, obj);
            }

            regions_dev.append(obj.key, obj.value, obj);

            new T200CityLoader(cities_dev, home_dev, element[4]);
        });
    }
}

class T200ContinentLoader {
    constructor(cities_dev, regions_dev, countries_dev, continents_dev, home_dev, data) {
        this.#load(cities_dev, regions_dev, countries_dev, home_dev, data);
    }

    #load(cities_dev, regions_dev, countries_dev, home_dev, data) {
        data.array().forEach(element => {
            let obj = {};

            obj.key = element[0];
            obj.value = element[1];
            obj.name = element[2];
            obj.data = element[3];

            continents_dev.append(obj.key, obj.value, obj);
            new T200RegionLoader(cities_dev, regions_dev, countries_dev, home_dev, element[3]);
        });
    }
}