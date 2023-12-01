const { log } = require('../T200Lib.js');
const T200Error = require('../T200Error.js');


class T200SQL {
    constructor() {

    }

    static CTEATE(value) {
        return `create ${value} `;
    }

    static DROP(value) {
        return `drop ${value} `;
    }

    static ALTER(value) {
        return `alter ${value} `;
    }

    static SELECT(fields, from, where, order, limit, offset) {
        let result = "select ";

        result += fields;
        result += from;
        result += undefined == where ? "" : where;
        result += undefined == order ? "" : order;
        result += undefined == limit ? "" : limit;
        result += undefined == offset ? "" : offset;
    
        return result;
    }

    static INSERT(name, fields, values) {
        return `insert into ${name} (${fields}) ${values} `;
    }

    static DELETE(value) {
        return `delete ${value} `;
    }

    static UPDATE(name, set, where) {
        return `update ${name} ${set} ${where} `;
    }

    ///
    static NAME(value) {
        return `${value} `;
    }

    static NAME_VALUE(items) {
        let result = "";
        let k = items.length;
        for(let i=0;i<k;i++){
            result += this.ASSIGN(items[i][0], items[i][1]);
            if(i < k - 1){
                result += ",";
            }
        }
        return result;
    }

    static SET(value) {
        return `set ${value}`;
    }

    static ASSIGN(left, right) {
        return `${left} = ${right} `;
    }

    static FIELDS(items) {
        return `${items} `;
    }

    static VALUES(value) {
        return `values (${value}) `;
    }

    static FROM(value) {
        return `from ${value} `;
    }

    static WHERE(value) {
        return `where ${value} `;
    }

    static ORDER(value) {
        return `order by ${value} `;
    }

    static DESC(value) {
        return `${value} desc `;
    }

    static LIMIT(value) {
        return `limit ${value} `;
    }

    static OFFSET(value) {
        return `offset ${value} `;
    }

    static MATCH(value) {
        return `match(${value}) `;
    }

    static AGAINST(value) {
        return `against(${value}) `;
    }

    ///
    static AND(left, right) {
        return `${left} and ${right} `;
    }

    static OR(left, right) {
        return `${left} or ${right} `;
    }

    static NOT(value) {
        return `!${value} `;
    }

    ///
    static EQUAL(left, right) {
        return `${left} = ${right} `;
    }

    static GREATER_THAN(left, right) {
        return `${left} > ${right} `;
    }

    static LESS_THAN(left, right) {
        return `${left} < ${right} `;
    }

    static GREATER_EQUAL(left, right)  {
        return `${left} >= ${right} `;
    }

    static LESS_EQUAL(left, right) {
        return `${left} <= ${right} `;
    }

    static STRING(value) {
        return `'${value}'`;
    }
}

module.exports = T200SQL;