function OR() {

}

function AND() {

}

function NOT() {

}

function EQUAL(left, right) {
    return `${left} = ${right}`;
}

function SELECT(fields, from, where, order, limit, offset) {
    //return `select ${fields} ${from} ${where} ${order} ${limit} ${offset}`;
    let result = "select ";

    result += fields;
    result += " ";
    result += from;
    result += " ";
    result += undefined == where ? "" : where + " ";
    result += undefined == order ? "" : order + " ";
    result += undefined == limit ? "" : limit + " ";
    result += undefined == offset ? "" : offset + " ";

    return result;
}

function INSERT() {

}

function DELETE() {

}

function UPDATE() {

}

function AS() {

}

function FROM(name) {
    return `from ${name}`;
}

function WHERE(value) {
    return `where ${value}`;
}

function ON() {

}

function ORDER(value) {
    return `order by ${value}`;
}

function DESC(name) {
    return `${name} desc`;
}

function LIMIT(value) {
    return `limit ${value}`;
}

function OFFSET(value) {
    return `offset ${value}`;
}

function MATCH() {

}

function AGAINST() {

}

function INNER_JOIN() {
    
}

module.exports = { SELECT, FROM, WHERE, ORDER, DESC, LIMIT, OFFSET, EQUAL};