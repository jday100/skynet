let obj = {};

let field = {};

field.name = "user_id";
field.type = "integer";
field.primary = true;
field.auto_increment = true;
field.index = "INDEX";
field.default = 0;

obj.fields = new Array();

obj.fields.push(field);

obj.name = "person";

let result = JSON.stringify(obj);

console.log(result);