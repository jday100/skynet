function password_edit() {
    $.id("password_box").innerHTML = `
        <form id='password_form'>
            <input type="hidden" name="test">
            <div>
                <dl>
                    <dd>
                        <div>
                            <label style="width: 150px;">Old Password:</label>
                            <input type="password" name="opwd">
                        </div>
                        <div>
                            <label style="width: 150px;">New Password:</label>
                            <input type="password" name="pwd1">
                        </div>
                        <div>
                            <label style="width: 150px;">New Password:</label>
                            <input type="password" name="pwd2">
                        </div>
                    </dd>
                </dl>
            </div>
        </form>
    `;

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
    $.id("email_box").innerHTML = `
        <form id='email_form' onsubmit="return false;">
            <input type="hidden" name="test">
            <div>
                <dl>
                    <dd>
                        <div>
                            <label>Password:</label>
                            <input type="password" name="password">
                        </div>
                        <div>
                            <label>Email:</label>
                            <input type="text" id="email" name="email">
                            <button onclick="send_email();">Send</button>
                        </div>
                        <div>
                            <label>Code:</label>
                            <input style="width: 100px;" type="password" name="code">
                        </div>
                    </dd>
                </dl>                
            </div>
        </form>
    `;

    $.id("email_button").innerHTML = "Save";
    $.id("email_button").onclick = email_save;
}

function email_save() {
    let result = formtostring("email_form");
    $.post('/content/person/email/save', result, function(data){
        alert("Save Success!");
        $.id("email_title").value = $.id("email").value;
        $.id("email_box").innerHTML = "";
        $.id("email_button").innerHTML = "Edit";
        $.id("email_button").onclick = email_edit;        
    }, function(){
        alert("Save Failure!");
    });
}

function nationality_edit() {
    $.id("nationality_box").innerHTML = `
        <form id='nationality_form' onsubmit="return false;">
            <input type="hidden" name="test">
            <div>
                <dl>
                    <dd>
                        <div>
                            <label>Continent:</label>
                            <input type="hidden" id="continent_title" name="continent_title">
                            <select id="continent" name="continent" onchange="continent_dev_change(this, 'country');">
                            </select>
                        </div>
                        <div>
                            <label>Country:</label>
                            <input type="hidden" id="country_title" name="country_title">
                            <select id="country" name="country" onchange="country_dev_change(this, 'country_title');">
                            </select>
                        </div>
                    </dd>
                </dl>
            </div>
        </form>
    `;

    $.id("nationality_button").innerHTML = "Save";
    $.id("nationality_button").onclick = nationality_save;

    continents_dev_init($.id("continent"));
}

function nationality_save() {
    let result = formtostring("nationality_form");
    $.post('/content/person/nationality/save', result, function(data){
        alert("Save Success!");
        let continent_id = $.id("continent").value;
        let continent_name = $.id("continent").options[$.id("continent").selectedIndex].text;
        let country_id = $.id("country").value;
        let country_name = $.id("country").options[$.id("country").selectedIndex].text;
        $.id("nationality_box").innerHTML = `
        <div>
            <dl>
                <dd>
                    <div>
                        <label>Continent:</label>
                        <input type="hidden" id="continent_id" value="">
                        <input disabled type="text" id="continent_name" value="">
                    </div>
                    <div>
                        <label>Country:</label>
                        <input type="hidden" id="country_id" value="">
                        <input disabled type="text" id="country_name" value="">
                    </div>
                </dd>
            </dl>
        </div>
        `;
        $.id("continent_id").value = continent_id;
        $.id("continent_name").value = continent_name;
        $.id("country_id").value = country_id;
        $.id("country_name").value = country_name;
        $.id("nationality_button").innerHTML = "Edit";
        $.id("nationality_button").onclick = nationality_edit;        
    }, function(){
        alert("Save Failure!");
    });
}


function location_edit() {
    $.id("location_box").innerHTML = `
        <form id='location_form' onsubmit="return false;">
            <input type="hidden" name="test">
            <div>
                <dl>
                    <dd>
                        <div>
                            <label>Continent:</label>
                            <input type="hidden" id="continent_title" name="continent_title"> 
                            <select id="continent" name="continent" onchange="continent_dev_change(this, 'region');">
                            </select>
                        </div>
                        <div>
                            <label>Region:</label>
                            <input type="hidden" id="region_title" name="region_title">
                            <select id="region" name="region" onchange="region_dev_change('region', 'city');">
                            </select>
                        </div>
                        <div>
                            <label>City:</label>
                            <input type="hidden" id="city_title" name="city_title">
                            <select id="city" name="city" onchange="city_dev_change(this, 'city_title');">
                            </select>
                        </div>
                    </dd>
                </dl>
            </div>
        </form>
    `;

    $.id("location_button").innerHTML = "Save";
    $.id("location_button").onclick = location_save;

    continents_dev_init($.id("continent"));
}

function location_save() {
    let result = formtostring("location_form");
    $.post('/content/person/identity/location/save', result, function(data){
        alert("Save Success!");

        let continent_id = $.id("continent").value;
        let continent_name = $.id("continent").options[$.id("continent").selectedIndex].text;
        let region_id = $.id("region").value;
        let region_name = $.id("region").options[$.id("region").selectedIndex].text;
        let city_id = $.id("city").value;
        let city_name = $.id("city").options[$.id("city").selectedIndex].text;
        
        $.id("location_box").innerHTML = `
        <div>
            <dl>
                <dd>
                    <div class="region">
                        <label>Continent:</label>
                        <input type="hidden" id="continent_id" value="">
                        <input disabled type="text" id="continent_name" value="">
                    </div>
                    
                    <div class="region">
                        <label>Region:</label>
                        <input type="hidden" id="region_id" value="">
                        <input disabled type="text" id="region_name" value="">
                    </div>

                    <div class="region">
                        <label>City:</label>
                        <input type="hidden" id="city_id" value="">
                        <input disabled type="text" id="city_name" value="">
                    </div>
                </dd>
            </dl>
        </div>
        `;
        $.id("continent_id").value = continent_id;
        $.id("continent_name").value = continent_name;
        $.id("region_id").value = region_id;
        $.id("region_name").value = region_name;
        $.id("city_id").value = city_id;
        $.id("city_name").value = city_name;
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
    $.post('/content/person/identity/intro/save', result, function(data){
        alert("Save Success!");
        $.id("intro").disabled = true;
        $.id("intro_button").innerHTML = "Edit";
        $.id("intro_button").onclick = intro_edit;        
    }, function(){
        alert("Save Failure!");
    });
}

function profile_intro_edit() {
    $.id("intro").disabled = false;
    $.id("intro_button").innerHTML = "Save";
    $.id("intro_button").onclick = profile_intro_save; 
}

function profile_intro_save() {
    let result = formtostring("intro_form");
    $.post('/content/person/profile/intro/save', result, function(data){
        alert("Save Success!");
        $.id("intro").disabled = true;
        $.id("intro_button").innerHTML = "Edit";
        $.id("intro_button").onclick = profile_intro_edit;        
    }, function(){
        alert("Save Failure!");
    });
}

function send_email() {

}

function date_init(year, month, day) {
    let result = "";
    for(let i=1920;i<=2023;i++){
        result += `
            <option value="${i}">${i}</option>
        `;
    }
    year.innerHTML = result;

    result = "";
    for(let i=1;i<=12;i++){
        result += `
            <option value="${i}">${i}</option>
        `;
    }
    month.innerHTML = result;

    result = "";
    for(let i=1;i<=31;i++){
        result += `
            <option value="${i}">${i}</option>
        `;
    }
    day.innerHTML = result;
}


function continent_change(obj, id) {
    let items = regions[obj.value];

    if(undefined == items){

    }else{
        let result = "";
        items.forEach(item => {
            result += `<option value='${item}'>${item}</option>`;
        });
        $.id(id).innerHTML = result;
        $.id(id).value = "";
    }
}

function region_change(obj, id) {
    let items = cities[obj.value];

    if(undefined == items){

    }else{
        let result = "";

        for(let item in items){
            result += `<option value='${items[item]}'>${item}</option>`;
        }
        $.id(id).innerHTML = result;
    }
}

