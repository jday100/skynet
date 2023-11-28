function list_hit_search() {

}

function list_hit_page() {

}

function list_hit_delete() {

}

function list_hit_edit() {

}

function list_hit_update() {

}

function list_change_status() {
    
}

function list_hit_approve(id, obj, url) {
    let result = formtostring(id);
    $.post(url, result, function(data){
        reload();
    }, function(){
        alert("Save Failure!");
    });
}