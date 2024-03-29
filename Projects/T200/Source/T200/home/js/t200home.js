var StatusType = {
    unreviewed : 0,
    reviewed : 1,
    deleted : -1
};

/*
function login() {
    $.set_cookie('sid', 1);
    alert('Login Success!');
    forward("/");
}
*/

function logout() {
    let url = "/logout";
    let result = "test=";
    $.post(url, result, function(data){
        $.set_path_cookie('sid', 0, '/');
        location.reload();
    }, function(){
        $.set_path_cookie('sid', 0, '/');
        location.reload();
    });
}

function flush(page) {
    let loc = location;

    let url = location.origin + location.pathname;

    let search = "?page=" + page;

    location.href = url + search;
}

function reload() {
    location.reload();
}

/*
function logout() {
    $.set_cookie('sid', 0);
    location.reload();
}
*/

function nav_check() {
    let sid = $.cookie('sid');

    if(sid && 0 < sid){
        $.id('nav_right').innerHTML = '<a href="/content/index.html" locale="my">My</a> | <a href="#" onclick="logout();" locale="logout">Logout</a>';
    }
}

function redirect(action) {
    $.win.location = action;
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
    $.id('search').value = $.id('search_input').value;
    let result = formtostring(id);
    $.post(url, result, function(data){
        obj.innerHTML = data;
        update_time();
    }, function(){
        alert("Search Failure!");
    });
}

function hit_follow(name, id) {
    let result = `test=&id=${id}`;
    let url = "/content/person/follow";
    $.post(url, result, function(data){
        $.id(name).innerHTML = "";
    }, function(){
        alert("Follow Failure!");
    });
}

function hit_message(id, name) {
    oct_open_message(id, name);
}

function hit_reply(id, obj, url) {
    let result = formtostring(id);
    $.post(url, result, function(data){
        obj.innerHTML = data;
    }, function(){
        alert("Save Failure!");
    });
}

function show_reply(parent_id, parent_nickname, id, page, nickname, obj, url) {
    if('reply' == $.id("reply"+id).textContent){
        let result = " \
            <form id='"
            + "form_" + id +
            "' class='reply_form' onsubmit='return false;'> \
            <input type='hidden' name='test'> \
            <input type='hidden' name='page' value='"
            + page + 
            "'> \
            <input type='hidden' name='id' value='"
            + parent_id +
            "'> \
            <div class='reply_group'> \
            <textarea name='content'></textarea> \
            <button class='reply_button' onclick='reply_save(\""
            + id +
            "\"," +
            "$.id(\"" + obj + "\"),\""
            + url +
            "\");'>Save</button> \
            </div> \
            </form> \
        ";


        result = `
            <form id='form_${id}' class='reply_form' onsubmit='return false;'>
                <input type='hidden' name='test'>
                <input type='hidden' name='page' value='${page}'>
                <input type='hidden' name='parentid' value='${parent_id}'>
                <input type='hidden' name='parentnickname' value='${parent_nickname}'>
                <input type='hidden' name='nickname' value='${nickname}'>
                <div class='reply_group'>
                    <textarea name='content'></textarea>
                    <button class='reply_button' onclick='reply_save(${id}, $.id(\"${obj}\"), \"${url}\");'>Save</button>
                </div>
            </form>
        `;


        $.id("reply_box" + id).innerHTML = result;
        $.id("reply" + id).textContent = "hidden";
    }else{
        $.id("reply_box" + id).innerHTML = "";
        $.id("reply" + id).textContent = "reply";
    }
}

function reply_save(id, obj, url) {
    let result = formtostring('form_' + id);
    $.post(url, result, function(data){
        alert("Save Success!");
        /*$.id("reply_box" + id).innerHTML = "";
        $.id("reply" + id).textContent = "reply";
        */
       /*reload();*/
        obj.innerHTML = data;
    }, function(){
        alert("Save Failure!");
    });
}

function turning(id, obj, url) {
    let result = `test=&page=${id}`;
    $.post(url, result, function(data){
        obj.innerHTML = data;
        update_time();
    }, function(){
        alert("Load Failure!");
    });
}

function turning_page(id, obj, url) {
    $.id("page").value = id;
    let result = formtostring("form");
    $.post(url, result, function(data){
        obj.innerHTML = data;
        update_time();
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

function set_region(data) {
    if(undefined == data || undefined == regions_dev || undefined == cities_dev){

    }else{
        let region = regions_dev.key(data.region_id);

        if(undefined == region){
            return;
        }else{
            $.id("region").value = region.name;
        }

        let city = cities_dev.key(data.city_id);

        if(undefined == city){

        }else{
            let obj = JSON.parse(city.data);

            if(undefined == obj){

            }else{
                $.id("city").value = obj.name;
            }
        }
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

function get_id() {
    let query = location.search;

    if(null == query){
        
    }else{
        if(-1 != query.indexOf("?")) {
            let str = query.slice(1);
            let values = str.split("=");

            if(2 == values.length){
                if("id" == values[0]){
                    return values[1];
                }
            }
        }
    }

    return 0;
}

function query_pid() {
    let query = location.search;

    if(null == query){

    }else{
        if(-1 != query.indexOf("?")) {
            let str = query.slice(1);
            let values = str.split("=");

            if(2 == values.length){
                if("id" == values[0]){
                    $.set_cookie("id", values[1]);
                    $.id("id").value = values[1];
                }
            }
        }
    }
}

function update_id(url, name, id) {
    let query = location.search;

    if(null == query){

    }else{
        if(-1 != query.indexOf("?")) {
            let str = query.slice(1);
            let values = str.split("=");

            if(2 == values.length){
                if("id" == values[0]){
                    $.set_cookie("id", values[1]);
                    $.id(id).value = values[1];
                    $.id(name).href = `${url}?id=${values[1]}`;
                }
            }
        }
    }
}

function update_city_id(parent_url, parent_name, child_url, child_name, id) {
    let query = location.search;

    if(null == query){

    }else{
        if(-1 != query.indexOf("?")) {
            let str = query.slice(1);
            let values = str.split("=");

            if(2 == values.length){
                if("id" == values[0]){
                    $.set_cookie("id", values[1]);
                    $.id(id).value = values[1];

                    $.id(parent_name).href = `${parent_url}?id=${values[1]}`;
                    $.id(child_name).href = `${child_url}?id=${values[1]}`;
                }
            }
        }
    }
}

function query_page() {
    let query = location.search;

    if(null == query){

    }else{
        if(-1 != query.indexOf("?")) {
            let str = query.slice(1);
            let values = str.split("=");

            if(2 == values.length){
                if("page" == values[0]){
                    $.id("page").value = values[1];
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

function update_times(name) {
    for(let i=0;i<10;i++){
        let obj = $.id(name+i);

        if(undefined == obj){
            //alert(1);
        }else{
            let value = show_short_time(obj.value);
            $.id(name+"_time"+i).innerHTML = value;
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


function show_date(source, target) {
    let value = $.id(source).value;

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
    
    $.id(target).value = result;
}


function show_short_time(value) {
    let ndate = new Date();
    let cdate = new Date(value);

    let result = "";

    if(ndate.getFullYear() == cdate.getFullYear()){
        if(ndate.getMonth() == cdate.getMonth()){
            if(ndate.getDate() == cdate.getDate()){
                result = ("0" + cdate.getHours().toString()).slice(-2)
                    + ":"
                    + ("0" + cdate.getMinutes().toString()).slice(-2)
                    + ":"
                    + ("0" + cdate.getSeconds().toString()).slice(-2);
            }else{
                result = ("0" + cdate.getDate().toString()).slice(-2)
                    + " "
                    + ("0" + cdate.getHours().toString()).slice(-2)
                    + ":"
                    + ("0" + cdate.getMinutes().toString()).slice(-2)
                    + ":"
                    + ("0" + cdate.getSeconds().toString()).slice(-2);
            }
        }else{
            result = ("0" + (cdate.getMonth() + 1).toString()).slice(-2) 
                    + "-"
                    + ("0" + cdate.getDate().toString()).slice(-2)
                    + " "
                    + ("0" + cdate.getHours().toString()).slice(-2)
                    + ":"
                    + ("0" + cdate.getMinutes().toString()).slice(-2)
                    + ":"
                    + ("0" + cdate.getSeconds().toString()).slice(-2);
        }
    }else{
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
    }

    return result;
}

function update_content_status() {
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
            $.id('status'+i).setAttribute("locale", value);
        }
    }
}