class T200 {
    constructor() {
        this.#load_cookies();
        this.win = window;
        this.doc = document;
        this.nav = navigator;
    }

    #load_cookies() {
        let self = this;
        this._cookies = {};
        document.cookie.split(';').forEach(item => {
            let values = item.split('=');
            self._cookies[ values[0].trim() ] = (values[1] || '').trim();
        });
    } 

    cookie(name) {
        return this._cookies[name];
    }

    set_cookie(name, value) {
        document.cookie = `${name}=${value}`;
    }

    set_path_cookie(name, value, path) {
        document.cookie = `${name}=${value};path=${path};`;
    }

    clear_cookie(name, value, path) {
        let time = Date.now();
        document.cookie = `${name}=${value}; path=${path}; Expires=${time};`;
    }

    static create() {
        return new T200();
    }

    id(flag) {
        return document.getElementById(flag);
    }

    name(flag) {
        return document.getElementsByName(flag);
    }

    find(flag) {
        return document.querySelectorAll(flag);
    }

    datatostring(data) {
        return new URLSearchParams(data).toString();
    }

    get(url, data, success, failure) {
        let xhr = new XMLHttpRequest();

        xhr.open('GET', url, true);
        xhr.send(data);
        xhr.addEventListener('load', function(){
            if(200 == xhr.status){
                success(xhr.response);
            }else{
                failure();
            }
        });
    }

    post(url, data ,success, failure) {
        let xhr = new XMLHttpRequest();

        xhr.open('POST', url, true);
        xhr.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded');
        xhr.send(data);
        xhr.addEventListener('load', function(){
            if(200 == xhr.status){
                let flag = JSON.parse(xhr.response);
                if('success' == flag.result){
                    success(flag.data);
                }else{
                    failure();
                }
            }else{
                failure();
            }
        });
    }
}

window.$ = T200.create();