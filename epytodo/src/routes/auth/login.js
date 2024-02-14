/*
** EPITECH PROJECT, 2021
** epytodo
** File description:
** login.js
*/

var glob = require('../../config/global');

const SECRET = glob.myenv.SECRET;

function error_handling_login(req) {
    if(!req.body.hasOwnProperty('email')) {
        console.log("no email");
        return (false);
    }
    if(!req.body.hasOwnProperty('password')) {
        console.log("no password");
        return (false);
    }
    return (true);
}

module.exports = async function(app, con) {
    app.post("/login", async (req, res) => {
        if (!error_handling_login(req)) {
            res.status(400).json({ msg: "Invalid Credentials" });
            return (400);
        }
        con.query(`SELECT * FROM user WHERE email = "${req.body.email}";`, function (err, rows) {
            if (err) res.status(500).json({ msg: "Internal server error" });
            if (rows[0] == undefined) {
                res.status(400).json({ msg: "Invalid Credentials" });
            } else {
                if (glob.bcrypt.compareSync(req.body.password, rows[0].password)) {
                    var token = glob.jwt.sign({ id: `${rows[0].id}` }, SECRET, { expiresIn: '1h' });
                    res.status(201).json({token: token});
                } else
                    res.status(400).json({ msg: "Invalid Credentials" });
            }
        });
    });
}
