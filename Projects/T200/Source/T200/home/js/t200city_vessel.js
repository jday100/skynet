class T200CityLoader {
    constructor(citis_dev, home_dev, data) {
        this.#load(citis_dev, home_dev, data);
    }

    #load(citis_dev, home_dev, data) {
        data.array().forEach(element => {
            if(element[2]){
                home_dev.append(element[0], element[1], element[3]);
            }

            citis_dev.append(element[0], element[1], element[3]);
        });
    }
}

class T200RegionLoader {
    constructor(cities_dev, regions_dev, countries_dev, home_dev, data) {
        this.#load(cities_dev, regions_dev, countries_dev, home_dev, data);
    }

    #load(cities_dev, regions_dev, countries_dev, home_dev, data) {
        data.array().forEach(element => {
            if(element[2]){
                countries_dev.append(element[0], element[1], element[3]);
            }

            regions_dev.append(element[0], element[1], element[3]);

            new T200CityLoader(cities_dev, home_dev, element[3]);
        });
    }
}

class T200ContinentLoader {
    constructor(cities_dev, regions_dev, countries_dev, continents_dev, home_dev, data) {
        this.#load(cities_dev, regions_dev, countries_dev, home_dev, data);
    }

    #load(cities_dev, regions_dev, countries_dev, home_dev, data) {
        data.array().forEach(element => {
            continents_dev.append(element[0], element[1], element[2]);
            new T200RegionLoader(cities_dev, regions_dev, countries_dev, home_dev, element[2]);
        });
    }
}