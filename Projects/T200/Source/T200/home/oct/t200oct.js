let oct_root_box;
let oct_box_flag;
let oct_panel_flag;
let oct_flash_flag = false;

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
        let self = this;
        let wss = new WebSocket("ws://localhost:8888/oct/server");

        wss.onopen = function(event) {
            wss.send(self.command(self.load()));
        }

        wss.onmessage = function(event) {
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
            self.close();
        }
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

        return cmd;
    }

    load() {
        let cmd = {};

        cmd.command = "load";

        return cmd;
    }

    list() {

    }

    receive() {

    }
}


function oct_box_click(parent) {
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
    oct_panel_flag = true;

    return false;
}

function oct_item_click(parent) {
    //alert(oct_root_box);

    let data = oct_root_box.innerHTML;

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
                <button onclick="oct_flash_click();">Flash</button>
                <button onclick="oct_send_click();">Send</button>
            </div>
        </div>
    `;

    oct_root_box.innerHTML = value + data;

    let dialog = $.id(`oct_send_dialog`).contentWindow;

    dialog.document.open();
    dialog.document.writeln('<html><head><link rel="stylesheet" href="/oct/t200oct_dev.css"></head><body></body></html>');
    dialog.document.close();




    let editor = $.id(`oct_send_text`).contentWindow;

    editor.document.designMode = "on";
    editor.document.contentEditable = true;

    editor.document.open();
    editor.document.writeln('<html><body></body></html>');
    editor.document.close();

    return false;
}

function oct_send_click() {
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

    return false;
}

function oct_send_close() {
    oct_box_click($.id('oct_box'));

    return false;
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