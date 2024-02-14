/*
** EPITECH PROJECT, 2021
** epytodo
** File description:
** user.js
*/

var glob = require('../../config/global');

const SECRET = glob.myenv.SECRET;

function get_id_with_token(req, res) {
    try {
        var decoded = glob.jwt.verify(req.token, SECRET);
        return (decoded.id);
    } catch (err) {
        res.status(403).json({ msg: "Token is not valid" });
    }
    return (-1);
}

module.exports = async function(app, con) {
    app.get("/user", glob.verifyToken, async (req, res) => {
        con.query(`SELECT * FROM user;`, function (err2, rows) {
            if (err2) res.status(500).json({ msg: "Internal server error" });
            res.send(rows);
        });
    });

    app.get("/user/todos", glob.verifyToken, async (req, res) => {
        id = get_id_with_token(req, res);
        if (id === -1) {
            res.status(403).json({ msg: "Token is not valid" });
            return;
        } else {
            con.query(`SELECT id FROM user WHERE id = "${id}";`, function (err2, rows) {
                if (err2) res.status(500).json({ msg: "Internal server error" });
                if (rows[0] && rows[0].id == id)
                    con.query(`SELECT * FROM todo WHERE user_id = ${id};`, function (err2, rows) {
                        if (err2) res.status(500).json({ msg: "Internal server error" });
                        if (rows[0])
                            res.send(rows);
                        else
                            res.status(200).json({ msg: "Not found"});
                    });
                else
                    res.status(403).json({ msg: "Token is not valid" });
            });
        }
    });
}
