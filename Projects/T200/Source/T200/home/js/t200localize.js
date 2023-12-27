class T200Localize {
    constructor() {
        this.#load();
    }

    #load() {
        let language = navigator.language;

        /*
        alert(language);

        language = navigator.browserLanguage;

        alert(language);
        */

        if("zh-CN" == language || "zh" == language){

        }else{
            return;
        }

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
                    let value = obj[element.getAttribute('locale')];
                    if(undefined == value){

                    }else{
                        element.innerHTML = value;
                    }                    
                }else if('DIV' == element.nodeName){
                    let value = obj[element.getAttribute('locale')];
                    if(undefined == value){

                    }else{
                        element.innerHTML = value;
                    }  
                }else if('LABEL' == element.nodeName){
                    let value = obj[element.getAttribute('locale')];
                    if(undefined == value){

                    }else{
                        element.innerHTML = value;
                    }  
                }else if('BUTTON' == element.nodeName){
                    let value = obj[element.getAttribute('locale')];
                    if(undefined == value){

                    }else{
                        element.innerHTML = value;
                    }  
                }else if('LEGEND' == element.nodeName){
                    let value = obj[element.getAttribute('locale')];
                    if(undefined == value){

                    }else{
                        element.innerHTML = value;
                    }  
                }else if('SUMMARY' == element.nodeName){
                    let value = obj[element.getAttribute('locale')];
                    if(undefined == value){

                    }else{
                        element.innerHTML = value;
                    }  
                }
            });
        }, function(){

        });
    }

    flush() {
        alert(1);
    }
}