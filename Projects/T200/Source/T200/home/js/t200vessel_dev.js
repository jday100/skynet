let contients = new T200Vessel([
    [100,   'asia'],
    [101,   'america'],
    [102,   'europe'],
    [103,   'oceania'],
    [104,   'africa'],
    [105,   'other']    
]);

let value = contients.key(101);

alert(value);

value = contients.value('asia');

alert(value);

value = contients.at(2);

alert(value);