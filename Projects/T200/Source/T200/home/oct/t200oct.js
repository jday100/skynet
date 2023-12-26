let oct_client;
let oct_root_box;
let oct_box_flag;


class T200OctClient {
    constructor(url, port) {
        let ws = new WebSocket("ws://localhost:8888/oct/server");

        ws.onopen = function(event) {
            let cmd = T200OctClient.load();
            ws.send(T200OctClient.command(cmd));
        };

        ws.onmessage = function(event) {
            
            /*alert('message');
    
            let cmd = T200OctClient.message("nice to meet you");
            cmd.id = 1;
            ws.send(T200OctClient.command(cmd));*/

            let cmd = JSON.parse(event.data);

            if(cmd){
                switch(cmd.command){
                    case 'list':
                        T200OctClient.list(cmd);
                        break;
                }
            }
        };

        ws.onclose = function(event) {
            alert('close');
        }
    }

    static command(cmd) {
        return JSON.stringify(cmd);
    }

    static message(msg) {
        let cmd = {};

        cmd.command = "send";
        cmd.data = msg;

        return cmd;
    }

    static load() {
        let cmd = {};

        cmd.command = "load";

        return cmd;
    }

    static list(cmd) {
        if(cmd && cmd.data){
            oct_box_click($.id('oct_box'));
        }
    }
}


class T200Oct {
    constructor() {
        this.#create();
    }

    #create() {
        let node = document.createElement("div");
        document.body.appendChild(node);

        node.innerHTML = "<div id='oct_box' class='oct_box' onclick='oct_box_click(this);'><img src='/oct/oct.png'></div>";

        oct_client = new T200OctClient("/oct/server", 8888);
    }
}

function oct_box_click(parent) {
    let list = "";

    if(true == oct_box_flag)return;

    oct_root_box = parent;
    oct_box_flag = true;

    for(let i=0;i<10;i++){
        list += `
            <div onclick="oct_item_click(this);">
                <div>
                    Hello
                </div>
                <div>
                    Online
                </div>
            </div>
        `;
    }


    let panel = `
        <div class="oct_panel">
            ${list}
        </div>
    `;

    parent.innerHTML = panel;
}

function oct_item_click(parent) {
    //alert(oct_root_box);

    let data = oct_root_box.innerHTML;

    let value = `
        <div class="oct_send_box">
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
                <button onclick="oct_send();">Send</button>
            </div>
        </div>
    `;

    oct_root_box.innerHTML = value + data;

    let editor = $.id(`oct_send_text`).contentWindow;

    editor.document.designMode = "on";
    editor.document.contentEditable = true;

    editor.document.open();
    editor.document.writeln('<html><body></body></html>');
    editor.document.close();

}

function oct_send() {
    let result = $.id(`oct_send_text`).contentDocument.body.innerHTML;
    $.id('oct_send_text_value').value = result;

    let data = formtostring('oct_send_form');
    $.post('/oct/send', data, function(result){
 
    }, function(err){
        
    });
}