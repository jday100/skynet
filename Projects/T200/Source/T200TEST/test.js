const T200Define = require('./lib/T200Define.js');

let name = "./project/define/T200Person.txt";


T200Define.create(name).then(function(data){
    let obj = JSON.parse(data);

    
}, function(){

});