const { do_index } = require('./index.js');

global.action.use_get('/', do_index);