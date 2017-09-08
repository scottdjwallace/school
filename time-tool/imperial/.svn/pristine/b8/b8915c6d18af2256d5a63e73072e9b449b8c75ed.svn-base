var mongoose = require('mongoose');

var Schema = mongoose.Schema;

var UserSchema = new Schema({
    email : {
        type : String, 
        required : true,
        index : true
    }, 
    password : {
        type : String, 
        required : true
    },
    created : {
        type : Date,
        default : Date.now    
    }
});

mongoose.model('User', UserSchema);

console.log('        models/user initialized.');
