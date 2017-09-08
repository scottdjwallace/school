var express = require('express')
    , morgan = require('morgan')
    , compress = require('compression')
    , bodyParser = require('body-parser')
    , methodOverride = require('method-override')
    , session = require('express-session');

var config = require('./env/development');

module.exports = function(){
    var app = express();

    app.use(morgan('dev'));
    app.use(bodyParser.urlencoded({ extended : true }));
    app.use(methodOverride());
    app.use(session({
        saveUninitialized : true,
        resave : true,
        secret : config.sessionSecret,
        cookie : {
            maxAge : 1000 * 3600 * 48
        }
    }));

    // setup views

    console.log('    initializing routes...');
    require('../app/routes/dev.server.routes.js')(app);
    require('../app/routes/user.server.routes.js')(app);

    app.use(express.static('./public'));

    console.log('    routes initialized.');

    return app;
};

