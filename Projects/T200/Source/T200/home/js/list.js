function list_hit_search(id, obj, url) {
    $.id("page").value = 1;
    $.id("status").value = '';
    $.id("search").value = $.id("search_key").value;
    let result = formtostring(id);
    $.post(url, result, function(data){
        obj.innerHTML = data;
        update_status();
        update_time();
    }, function(){
        alert("Search Failure!");
    });
}

function list_hit_page(id, page, obj, url) {
    $.id("page").value = page;
    let result = formtostring(id);
    $.post(url, result, function(data){
        obj.innerHTML = data;
        update_status();
        update_time();
    }, function(){
        alert("Load Failure!");
    });
}

function list_hit_delete(id, obj, url) {
    let result = formtostring(id);
    $.post(url, result, function(data){
        reload();
    }, function(){
        alert("Save Failure!");
    });
}

function list_hit_edit() {

}

function list_hit_update() {

}

function list_change_status(value, id, obj, url) {
    $.id('status').value = value;
    let result = formtostring(id);
    $.post(url, result, function(data){
        obj.innerHTML = data;
        update_status();
        update_time();
    }, function(){
        alert("Load Failure!");
    });
}

function list_hit_approve(id, obj, url) {
    let result = formtostring(id);
    $.post(url, result, function(data){
        reload();
    }, function(){
        alert("Save Failure!");
    });
}

var list_select_status = true;

function list_select_all() {
    $.name('ids').forEach(element => {
        element.checked = list_select_status;
    });

    list_select_status = !list_select_status;
}