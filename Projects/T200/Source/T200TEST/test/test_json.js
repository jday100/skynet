let value = {};

value.items = new Array();

let obj = {};
obj.name = "name";
obj.value = "value";

value.items.push(obj);
value.items.push(obj);

value.item = obj;
value.tag = obj;

let result = JSON.stringify(value);

console.log(result);