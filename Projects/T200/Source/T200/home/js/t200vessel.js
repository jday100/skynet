class T200Vessel {
    constructor(items) {
        this.#init(items);
    }

    #init(items) {
        let self = this;
        this._key_value = {};
        this._value_key = {};
        this._array = new Array();
        if(items){
            items.forEach(item => {
                self._key_value[item[0]] = item;
                self._value_key[item[1]] = item;
                self._array.push(item);
            });
        }
    }

    key(name) {
        let value = this._key_value[name];
        return value;
    }

    value(name) {
        let value = this._value_key[name];
        return value;
    }

    at(index) {
        let value;
        let length = this._array.length;

        if(index > length){

        }else{
            value = this._array.at(index);
        }
        return value;
    }

    append(key, name, value) {
        this._key_value[key] = value;
        this._value_key[name] = value;
        this._array.push(value);
    }

    array() {
        return this._array;
    }
}

