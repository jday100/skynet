var StatusType = {
    unreviewed : 0,
    reviewed : 1,
    deleted : -1
};


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
        alert("Please set the location in the profile first!");
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

function query_id() {
    let query = location.search;

    if(null == query){

    }else{
        if(-1 != query.indexOf("?")) {
            let str = query.slice(1);
            let values = str.split("=");

            if(2 == values.length){
                if("id" == values[0]){
                    $.set_cookie("id", values[1]);
                }
            }
        }
    }
}

function update_status() {
    for(let i=0;i<10;i++){
        let obj = $.id('id'+i);

        if(undefined == obj){
            //alert(1);
        }else{
            let value;
            switch(obj.value){
                case '-1':
                    value = 'deleted';
                    break;
                case '0':
                    value = 'unreviewed';
                    break;
                case '1':
                    value = 'reviewed';
                    break;
            }
            $.id('status'+i).value = value;
        }
    }
}


function hit_delete(id, obj, url) {
    let result = `test=&page=${id}`;
    $.post(url, result, function(data){
        obj.innerHTML = data;
    }, function(){
        alert("Load Failure!");
    });
}


function hit_approve(id, obj, url) {
    let result = `test=&page=${id}`;
    $.post(url, result, function(data){
        obj.innerHTML = data;
    }, function(){
        alert("Load Failure!");
    });
}


function change_status() {

}

function update_time() {
    for(let i=0;i<10;i++){
        let obj = $.id('time'+i);

        if(undefined == obj){
            //alert(1);
        }else{
            let value = show_time(obj.value);
            $.id('time_title'+i).value = value;
        }
    }
}


function show_time(value) {
    let cdate = new Date(value);

    let result = "";

    result = cdate.getFullYear().toString() 
        + "-"
        + ("0" + (cdate.getMonth() + 1).toString()).slice(-2) 
        + "-"
        + ("0" + cdate.getDate().toString()).slice(-2)
        + " "
        + ("0" + cdate.getHours().toString()).slice(-2)
        + ":"
        + ("0" + cdate.getMinutes().toString()).slice(-2)
        + ":"
        + ("0" + cdate.getSeconds().toString()).slice(-2);
    return result;
}