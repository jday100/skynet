let obj = {};

obj.name = "name";
obj.type = "type";
obj.locate = {};
obj.locate.type = "type";
obj.locate.value = '"value"';
obj.fields = [
    ["name", "type", 1],
    ["name", "type", 2]
];


let result = JSON.stringify(obj);

console.log(result);