const { do_index, do_datum } = require('./index.js');
const { do_region_index, do_city_index } = require('./region/region_index.js');

global.action.use_get('/', do_index);

global.action.use_get('/region/region.html', do_region_index);
global.action.use_get('/region/city.html', do_city_index);


global.action.use_get('/images/upload', do_datum);