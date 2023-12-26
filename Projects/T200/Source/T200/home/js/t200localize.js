class T200Localize {
    constructor() {
        this.#load();
    }

    #load() {
        let url = "/i18n/zh_CN.properties";
        $.get(url, {}, function(data){
            //alert(data);

            //alert($.find("[locale]"));

            let obj = {};

            data.split("\n").forEach(element => {
                let values = element.split("=");
                obj[values[0]] = values[1];
            });

            //alert(obj);

            $.find("[locale]").forEach(element => {
                //alert(element.getAttribute('locale'));

                //alert(obj[element.getAttribute('locale')]);

                //alert(element.nodeName);
                if('A' == element.nodeName){
                    element.innerHTML = obj[element.getAttribute('locale')];
                }else if('DIV' == element.nodeName){
                    element.innerHTML = obj[element.getAttribute('locale')];
                }else if('LABEL' == element.nodeName){
                    element.innerHTML = obj[element.getAttribute('locale')];
                }else if('BUTTON' == element.nodeName){
                    element.innerHTML = obj[element.getAttribute('locale')];
                }
            });
        }, function(){

        });
    }

    flush() {
        alert(1);
    }
}