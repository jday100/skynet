class T200Editor {
    constructor(parent, name, width, height) {
        this.#create(parent, name, width, height);
    }

    #create(parent, name, width, height) {
        this._name = name;
        let result = `
            <iframe id="${name}_iframe", style="width:${width}px;height:${height}px;background-color:white;" marginWidth="0" marginHeight="0"></iframe>
            <textarea id="${name}" style="width:0px;height:0px;display:none;" name="${name}">
        `;

        $.id(parent).innerHTML = result;

        let editor = $.id(`${name}_iframe`).contentWindow;

        editor.document.designMode = "on";
        editor.document.contentEditable = true;

        editor.document.open();
        editor.document.writeln('<html><body></body></html>');
        editor.document.close();
    }

    upload(name, id) {
        if(undefined == id){
            return;
        }
        this._id = id;
        $.id(name).innerHTML = `
            <div id="${id}_list" style="width:100%">
            </div
            <div style="width:100%">
            <input type="file" id="${id}" name="${id}" multiple="multiple">
            </div>
        `;

        $.id(id).onchange = this.change;
    }

    change() {
        let form = $.id('form');
        let data = new FormData(form);
        data.contentType = false;
        data.enctype="multipart/form-data";

        $.upload('/content/exchange/upload', data, function(){
            alert('Save Success!');
        }, function(){
            alert('Save Failure!');
        });
    }

    flush() {
        let result = $.id(`${this._name}_iframe`).contentDocument.body.innerHTML;
        $.id(this._name).value = result;
    }

    file(id, name) {
        let result = `
            <div>
                <div>
                    <label>FileName:</label>
                    <input type="text" id="file${id}" disabled value="${name}">
                </div>
                <div>
                    <button onclick="insert('${this._name}_iframe', 'file${id}');">Insert</button>
                </div>
            </div>
        `;
        $.id(`${this._id}_list`).innerHTML += result;
    }

    insert() {
        alert(1);
    }

}


function insert(name, id) {
    //alert($.id(name).contentWindow.document.selection);
    //$.id(name).contentDocument.selection.createRange().pasteHTML("1");

    //$.id(name).contentWindow.document.write(2);
    //$.id(name).contentWindow.document.activeElement.innerHTML= "2";

    //alert(window.getSelection());

    //alert($.id(name).contentWindow.getSelection());

    let selection = $.id(name).contentWindow.getSelection();

    let range = selection.getRangeAt(selection.rangeCount - 1);

    let element = $.id(name).contentDocument.createElement("img");

    element.src = $.id(id).value;

    range.deleteContents();
    range.insertNode(element);

}