class T200Editor {
    constructor(parent, name, width, height) {
        this.#create(parent, name, width, height);
    }

    #create(parent, name, width, height) {
        let result = `
            <iframe id="${name}", style="width:${width}px;height:${height}px" marginWidth="0" marginHeight="0"></iframe>
            <textarea id="${name}_value" style="width:0px;height:0px" name="${name}">
        `;

        $.id(parent).innerHTML = result;

        let editor = $.id(`${name}`).contentWindow;

        editor.document.designMode = "on";
        editor.document.contentEditable = true;

        editor.document.open();
        editor.document.writeln('<html><body></body></html>');
        editor.document.close();

        $.id(name).onchange = function(){
            alert(1);
            $.id(`${name}_value`).value= $.id(name).innerHTML;
        };
    }

    upload(name) {
        $.id(name).innerHTML = `
            <input type="file" name="file">
        `;
    }

}