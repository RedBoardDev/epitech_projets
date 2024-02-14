/*
** EPITECH PROJECT, 2021
** epytodo
** File description:
** auth.js
*/

var glob = require('../../config/global');

const SECRET = glob.myenv.SECRET;

function error_handling_register(req) {
    if(!req.body.hasOwnProperty('email')) {
        console.log("no email");
        return (false);
    }
    if(!req.body.hasOwnProperty('name')) {
        console.log("no name");
        return (false);
    }
    if(!req.body.hasOwnProperty('firstname')) {
        console.log("no firstname");
        return (false);
    }
    if(!req.body.hasOwnProperty('password')) {
        console.log("no password");
        return (false);
    }
    return (true);
}

module.exports = async function(app, con) {
    app.post("/register", async (req, res) => {
        if (!error_handling_register(req)) {
            res.status(400).json({ msg: "Bad parameter" });
            return (400);
        }
        var salt = glob.bcrypt.genSaltSync(10);
        var hash = glob.bcrypt.hashSync(req.body['password'], salt);
        con.query(`SELECT * FROM user WHERE email = "${req.body.email}";`, function (err, rows) {
            if (err) res.status(500).json({ msg: "Internal server error" });
            if (rows[0] != undefined) {
                res.status(418).json({msg: "Account already exists"});
            } else {
                con.query(`INSERT INTO user(email, password, name, firstname) VALUES("${req.body["email"]}", "${hash}", "${req.body["name"]}", "${req.body["firstname"]}")`, function (err2, result) {
                    if (err2) res.status(500).json({ msg: "Internal server error" });
                });
                con.query(`SELECT * FROM user WHERE email = "${req.body.email}";`, function (err3, rows) {
                    if (err3) res.status(500).json({ msg: "Internal server error" });
                    if (rows != undefined && rows[0] != undefined) {
                        var token = glob.jwt.sign({ id: `${rows[0].id}` }, SECRET, { expiresIn: '1h' });
                        res.status(201).json({token: token});
                    } else
                        res.status(400);
                });
            }
        });
    });
}
