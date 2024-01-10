let oct_root_box;
let oct_box_flag;
let oct_panel_flag = false;
let oct_flash_flag = false;
let oct_item_flag = false;
let oct_panel_close_flag = false;

let oct_panel_html;

class T200Oct {
    constructor() {
        this.#create();
    }

    #create() {
        let node = document.createElement("div");

        document.body.appendChild(node);

        node.innerHTML = `
            <div id='oct_box' class='oct_box' onclick='oct_box_click(this);'>
                <img src='/oct/oct.png'>
            </div
        `;
    }

    open() {
        alert("open");
        let self = this;
        let wss = new WebSocket("ws://localhost:8888/oct/server");

        wss.onopen = function(event) {
            wss.send(self.command(self.load()));
        }

        wss.onmessage = function(event) {
            alert("msg");
            let cmd = JSON.parse(event.data);

            if(cmd){
                switch(cmd.command){
                    case 'list':
                        self.list(cmd);
                        break;
                    case 'receive':
                        self.receive(cmd);
                        break;
                }
            }
        }

        wss.onclose = function(event) {
            alert("close");
            self.close();
        }

        this._wss = wss;
    }

    close() {

    }

    command(cmd) {
        if(undefined == cmd)return "";

        return JSON.stringify(cmd);
    }

    message(msg) {
        let cmd = {};

        if(undefined == msg)return cmd;

        cmd.command = "send";
        cmd.data = msg;
        cmd.id = $.id("oct_id").value;

        return cmd;
    }

    load() {
        let cmd = {};

        cmd.command = "load";

        return cmd;
    }

    list(cmd) {
        alert("list");

        if(oct_panel_flag)return;

        if(undefined == cmd)return;

        let data = cmd.data;

        if(undefined == data)return;

        let list = "";
        let length = data.length;


        for(let i=0;i<length;i++){
            let element = data[0];
            list += `
                <div id="oct_item${element.identity_id}" onclick="oct_item_click(${element.identity_id});">
                    <div>
                        ${element.nickname}
                    </div>
                    <div>

                    </div>
                </div>
            `;
        }

        let panel = `
            <div id="oct_panel" class="oct_panel">
                <img onclick="oct_panel_close();" src="/images/cross.png">
                <div id="oct_list">
                    ${list}
                </div>                
            </div>
        `;

        $.id("oct_box").innerHTML = panel;

        oct_panel_flag = true;
        oct_panel_html = panel;
    }

    receive(cmd) {
        if(undefined == cmd){

        }else{
            oct_receive_message(cmd.id, cmd.data);
        }        
    }

    send(msg) {
        let value = window.btoa(encodeURI(msg));
        this._wss.send(this.command(this.message(value)));
    }
}


function oct_box_click(parent) {
    alert("box click");

    if(oct_item_flag)return;
    if(oct_panel_flag){
        if(oct_panel_close_flag){
            oct_panel_flag = false;
            oct_panel_close_flag = false;
        }else{

        }
    }else{
        oct_client.open();
    }    

    return;



    let list = "";

    if(true == oct_box_flag){
        if(true == oct_panel_flag){
            oct_box_flag = false;
            return;
        }else{
            return;
        }
    }

    oct_root_box = parent;
    oct_box_flag = true;

    for(let i=0;i<10;i++){
        list += `
            <div id="item${i}" onclick="oct_item_click(this);">
                <div>
                    Hello
                </div>
                <div>

                </div>
            </div>
        `;
    }


    let panel = `
        <div id="oct_panel" class="oct_panel">
            <img onclick="oct_panel_close();" src="/images/cross.png">
            ${list}
        </div>
    `;

    parent.innerHTML = panel;

    return false;
}


function oct_panel_close() {
    $.id("oct_box").innerHTML = "<img src='/oct/oct.png'>";
    oct_panel_close_flag = true;
}

function oct_item_click(id) {
    //alert(oct_root_box);

    let value = `
        <div class="oct_send_box">
            <img onclick="oct_send_close();" src="/images/cross.png">
            <div class="oct_send_dialog">
                <iframe id="oct_send_dialog"></iframe>
            </div>
            <div class="oct_send_text">
                <iframe id="oct_send_text"></iframe>
            </div>
            <form id="oct_send_form" style="display:none;">
                <input type="hidden" name="test">
                <textarea id="oct_send_text_value" style="display:none;" name="oct_send_text"></textarea>
            </form>
            <div class=oct_send_button>
                <input type="hidden" id="oct_id" value="${id}">
                <button onclick="oct_flash_click();">Flash</button>
                <button onclick="oct_send_click();">Send</button>
            </div>
        </div>
    `;

    $.id("oct_box").innerHTML = value + oct_panel_html;

    let dialog = $.id(`oct_send_dialog`).contentWindow;

    dialog.document.open();
    dialog.document.writeln('<html><head><link rel="stylesheet" href="/oct/t200oct_dev.css"></head><body></body></html>');
    dialog.document.close();




    let editor = $.id(`oct_send_text`).contentWindow;

    editor.document.designMode = "on";
    editor.document.contentEditable = true;

    let result = `
        <html>
            <body>
            </body>
        </html>
    `;

    editor.document.open();
    editor.document.writeln(result);
    editor.document.onkeyup = function(event) {
        let code = event.charCode || event.keyCode;

        if(13 == code && event.ctrlKey){
            //alert("enter");
            oct_send_click();
        }
    };

    editor.document.onkeydown = function(event) {
        //alert(event.ctrlKey);
    };

    editor.document.close();

    oct_item_flag = true;

    return false;
}

function oct_send_click() {
    if(undefined == oct_client){

    }else{
        let value = $.id(`oct_send_text`).contentDocument.body.innerHTML;

        if(undefined == value){

        }else{
            oct_client.send(value);
        }        
    }




    /*
    alert("send");

    let value = $.id(`oct_send_text`).contentDocument.body.innerHTML;
    let result = $.id(`oct_send_dialog`).contentDocument.body.innerHTML;

    //if("" == result) {
    //    result = `<link rel="stylesheet" href="/oct/t200oct_dev.css">`;
    //}

    result += `
        <div class="oct_dialog_right">
            ${value}
        </div>
        <div class="oct_dialog_left">
            ${value}
        </div>
    `;

    $.id(`oct_send_dialog`).contentDocument.body.innerHTML = result;
    $.id(`oct_send_text`).contentDocument.body.innerHTML = "";

    $.id(`oct_send_dialog`).contentDocument.body.scroll(0, $.id(`oct_send_dialog`).contentDocument.body.scrollHeight);

    return false;
    */
}

function oct_send_close() {
    $.id("oct_box").innerHTML = oct_panel_html;
    oct_item_flag = false;
}

function oct_flash_click() {
    let id = setInterval("oct_flash()", 1000);
}

function oct_flash() {
    //alert(oct_flash_flag);
    for(let i=0;i<5;i++){
        if(oct_flash_flag){
            $.id(`item${i}`).style = "background-color:antiquewhite;";
        }else{
            $.id(`item${i}`).style = "background-color:chartreuse;";
        }
        
    }
    oct_flash_flag = !oct_flash_flag;
}

function oct_open_message(id, name) {
    //alert(name);

    oct_box_click($.id('oct_box'));

    oct_item_click($.id(`item${id}`));
}

function oct_receive_message(id, msg) {
    if(undefined == id || undefined == msg)return;

    let value = decodeURI(window.atob(msg));

    if(undefined == value){

    }else{
        /*
        let result = $.id(`oct_send_dialog`).contentDocument.body.innerHTML;
    
    
        result += `
            <div class="oct_dialog_left">
                ${value}
            </div>
        `;
    
        $.id(`oct_send_dialog`).contentDocument.body.innerHTML = result;   
        $.id(`oct_send_dialog`).contentDocument.body.scroll(0, $.id(`oct_send_dialog`).contentDocument.body.scrollHeight);
        */

        let item = $.id(`oct_item${id}`);

        if(undefined == item){
            oct_append_item(id, "name");
            oct_item_click(id);
        }else{

        }

        let result = $.id(`oct_send_dialog`).contentDocument.body.innerHTML;
    
    
        result += `
            <div class="oct_dialog_left">
                ${value}
            </div>
        `;
    
        $.id(`oct_send_dialog`).contentDocument.body.innerHTML = result;   
        $.id(`oct_send_dialog`).contentDocument.body.scroll(0, $.id(`oct_send_dialog`).contentDocument.body.scrollHeight);

    }
}


function oct_append_item(id, name) {
    let result = $.id("oct_list").innerHTML;

    let item = `
        <div id="oct_item${id}" onclick="oct_item_click(${id});">
            <div>
                ${name}
            </div>
            <div>

            </div>
        </div>
    `;

    result += item;

    $.id("oct_list").innerHTML = result;

    oct_panel_html = $.id("oct_box").innerHTML;
}