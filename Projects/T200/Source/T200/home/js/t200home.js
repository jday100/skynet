function login() {
    $.set_cookie('sid', 1);
    alert('Login Success!');
    forward("/");
}

function reload() {
    location.reload();
}

function logout() {
    $.set_cookie('sid', 0);
    location.reload();
}

function nav_check() {
    let sid = $.cookie('sid');

    if(sid && 0 < sid){
        $.id('nav_right').innerHTML = '<a href="/content/index.html">My</a> | <a href="#" onclick="logout();">Logout</a>';
    }
}

function forward(action) {
    $.id('main').innerHTML = `<div class="form_redirect"><a href="${action}">Redirect</a></div>`;
    $.win.location = action;
}

function formtostring(name) {
    let data = new FormData($.id(name));
    let result = $.datatostring(data);
    return result;
}

function hit(name, value) {
    $.set_cookie(name, value);
}

function hit_search(id, obj, url) {
    let result = formtostring(id);
    $.post(url, result, function(data){
        obj.innerHTML = data;
    }, function(){
        alert("Search Failure!");
    });
}

function turning(id, obj, url) {
    let result = `test=&page=${id}`;
    $.post(url, result, function(data){
        obj.innerHTML = data;
    }, function(){
        alert("Load Failure!");
    });
}

function update_region() {
    let result = ``;
    $.post('/content/person/region', result, function(data){
        set_region(data);
    }, function(){
        alert("Load Failure!");
    });
}

function set_region(value) {
    let result = city[value];

    if(undefined == result){

    }else{
        $.id("region").value = result[1];
        $.id("city").value = result[2];
    }
}