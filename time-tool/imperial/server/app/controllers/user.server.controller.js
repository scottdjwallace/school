module.exports = function(){
    var bcrypt = require('bcrypt');

    var User = require('mongoose').model('User');
    var respondError = require('./framework/respondError');
    
    var c = {};

    c.create = function(req, res, next){
        if (!req.body) return respondError(res, 400, 10, "body", { created : 0 });
        if (!req.body.email) return respondError(res, 400, 10, "email", { created : 0 });
        if (!req.body.password) return respondError(res, 400, 10, "password", { created : 0 });

        bcrypt.hash(req.body.password, 13, function(err, hash){
            if (err) return respondError(res, 500, err);
            
            var newUser = new User({
                email : req.body.email,
                password : hash
            });
            
            newUser.save(function(err, newUser){
                if (err) return respondError(res, 500, err, undefined, { created : 0 });
                
                console.log('');
                res.status(201).json({ 
                    email : newUser.email,
                    created : 1 
                });
            }); 
        });
    };

    c.logIn = function(req, res, next){
        if (!req.body) return respondError(res, 400, 10, "body");
        if (!req.body.email) return respondError(res, 400, 10, "email");
        if (!req.body.password) return respondError(res, 400, 10, "password");

        User.findOne({ 
            email : req.body.email
        }, function(err, userDoc){
            if (err) return respondError(res, 500, err);

            bcrypt.compare(req.body.password, userDoc.password, function(err, pwOkay){
                if (err) return respondError(res, 500, err);

                if (pwOkay){
                    req.session.email = req.email;
                    res.json({
                        loggedIn : true,
                        expires : req.session.cookie.expires.getTime()
                    });
                } else {
                    return respondError(res, 403, err, "access denied");
                }
            });
        });
    };

    c.get = function(req, res, next){
        if (!req.session) return res.json({
            email : undefined,
            loggedIn : false
        });

        if (!req.session.email) return res.json({
            email : undefined,
            loggedIn : false
        });
        
        if (req.session.email) return res.json({
            email : req.session.email,
            loggedIn : true
        });

        return respondErr(res, 500, "unknown"); 
    };

    return c;
};
