module.exports = function(app){
    var cUser = require('../controllers/user.server.controller.js')();
    
    app.post('/login', cUser.logIn);
    app.post('/users', cUser.create);

    app.get('/user', cUser.get);

    console.log('        user routes set.');
};
