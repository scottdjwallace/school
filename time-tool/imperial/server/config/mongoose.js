var config = require('./env/development');

var mongoose = require('mongoose');

module.exports = function(){
    console.log('    initializing mongoose...');

    var db = mongoose.connect(config.db);

    require('../app/models/user.server.model');
    // require('../app/models/ics.server.model');
    // require('../app/models/group.server.model');

    console.log('    mongoose initialized.');

    return db;
};
