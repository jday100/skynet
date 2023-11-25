function nickname_edit() {
    $.id("nickname_box").innerHTML = " \
        <form id='nickname_form'> \
            <div> \
                <label>Password</label> \
                <input type='password' name='password'> \
            </div> \
            <div> \
                <label>Nickname</label> \
                <input type='text' name='nickname'> \
            </div> \
        </form> \
    ";
    $.id("nickname_button").innerHTML = "Save";
    $.id("nickname_button").onclick = nickname_save;
}

function nickname_save() {
    let result = formtostring("nickname_form");
    $.post('/content/person/nickname/save', result, function(data){
        alert("Save Success!");
        $.id("nickname").disabled = true;
        $.id("nickname_button").innerHTML = "Edit";
        $.id("nickname_button").onclick = nickname_edit;
    }, function(){
        alert("Save Failure!");
    });
}

function password_edit() {
    $.id("password_box").innerHTML = " \
        <form id='password_form'> \
            <div> \
                <label>Old Password</label> \
                <input type='password' name='opwd'> \
            </div> \
            <div> \
                <label>New Password</label> \
                <input type='password' name='npwd1'> \
            </div> \
            <div> \
                <label>New Password</label> \
                <input type='password' name='npwd2'> \
            </div> \
        </form> \
    ";
    $.id("password_button").innerHTML = "Save";
    $.id("password_button").onclick = password_save;
}

function password_save() {
    let result = formtostring("password_form");
    $.post('/content/person/password/save', result, function(data){
        alert("Save Success!");
        $.id("password_box").innerHTML = "";
        $.id("password_button").innerHTML = "Edit";
        $.id("password_button").onclick = password_edit;
    }, function(){
        alert("Save Failure!");
    });
}

function email_edit() {
    $.id("email_box").innerHTML = " \
        <form id='email_form'> \
            <div> \
                <label>Old Password</label> \
                <input type='password' name='opwd'> \
            </div> \
            <div> \
                <label>New Password</label> \
                <input type='password' name='npwd1'> \
            </div> \
            <div> \
                <label>New Password</label> \
                <input type='password' name='npwd2'> \
            </div> \
        </form> \
    ";
    $.id("email_button").innerHTML = "Save";
    $.id("email_button").onclick = email_save;
}

function email_save() {
    let result = formtostring("email_form");
    $.post('/content/person/email/save', result, function(data){
        alert("Save Success!");
        $.id("email_box").innerHTML = "";
        $.id("email_button").innerHTML = "Edit";
        $.id("email_button").onclick = email_edit;
    }, function(){
        alert("Save Failure!");
    });
}

function nationality_edit() {
    $.id("nationality_box").innerHTML = " \
        <form id='nationality_form'> \
            <div> \
                <label>Old Password</label> \
                <input type='password' name='opwd'> \
            </div> \
            <div> \
                <label>New Password</label> \
                <input type='password' name='npwd1'> \
            </div> \
        </form> \
    ";
    $.id("nationality_button").innerHTML = "Save";
    $.id("nationality_button").onclick = nationality_save;
}

function nationality_save() {
    let result = formtostring("nationality_form");
    $.post('/content/person/nationality/save', result, function(data){
        alert("Save Success!");
        $.id("nationality_box").innerHTML = "";
        $.id("nationality_button").innerHTML = "Edit";
        $.id("nationality_button").onclick = nationality_edit;
    }, function(){
        alert("Save Failure!");
    });
}

function location_edit() {
    $.id("location_box").innerHTML = " \
            <form id='location_form'> \
                <input type='hidden' name='test'> \
                <div> \
                    <label>Continent:</label> \
                    <select id='continent' onchange='continent_change(this.value);'></select> \
                </div> \
                <div> \
                    <label>Continent:</label> \
                    <select id='region' onchange='region_change(this.value);'></select> \
                </div> \
                <div> \
                    <label>Continent:</label> \
                    <select id='city' name='city'></select> \
                </div> \
            </form> \
        ";

    continent_init($.id("continent"));

    $.id("location_button").innerHTML = "Save";
    $.id("location_button").onclick = location_save;
}

function location_save() {
    let result = formtostring("location_form");
    $.post('/content/person/location/save', result, function(data){
        alert("Save Success!");
        $.id("location_region").innerHTML = $.id("region").value;
        $.id("location_city").innerHTML = $.id("city").options[$.id("city").selectedIndex].text;
        $.id("location_box").innerHTML = "";
        $.id("location_button").innerHTML = "Edit";
        $.id("location_button").onclick = location_edit;
    }, function(){
        alert("Save Failure!");
    });
}


function intro_edit() {
    $.id("intro").disabled = false;
    $.id("intro_button").innerHTML = "Save";
    $.id("intro_button").onclick = intro_save;
}

function intro_save() {
    let result = formtostring("intro_form");
    $.post('/content/person/intro/save', result, function(data){
        alert("Save Success!");
        $.id("intro").disabled = true;
        $.id("intro_button").innerHTML = "Edit";
        $.id("intro_button").onclick = intro_edit;
    }, function(){
        alert("Save Failure!");
    });
}


function region_init(value) {
    let result = city[value];

    if(undefined == result){

    }else{
        $.id("location_region").innerHTML = result[1];
        $.id("location_city").innerHTML = result[2];
    }
}