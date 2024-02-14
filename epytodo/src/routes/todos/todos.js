/*
** EPITECH PROJECT, 2021
** epytodo
** File description:
** todos.js
*/

var glob = require('../../config/global');

const SECRET = glob.myenv.SECRET;

function get_id_with_token2(req, res) {
    try {
        var decoded = glob.jwt.verify(req.token, SECRET);
        return (decoded.id);
    } catch (err) {
        res.status(403).json({ msg: "Token is not valid" });
    }
    return (-1);
}

function error_handling_todo(req) {
    if(!req.body.hasOwnProperty('title')) {
        console.log("no title");
        return (false);
    }
    if(!req.body.hasOwnProperty('description')) {
        console.log("no description");
        return (false);
    }
    if(!req.body.hasOwnProperty('due_time')) {
        console.log("no due_time");
        return (false);
    }
    // if(!req.body.hasOwnProperty('user_id')) {
    //     console.log("no user_id");
    //     return (false);
    // }
    if(!req.body.hasOwnProperty('status')) {
        console.log("no status");
        return (false);
    }
    if (req.body.status != "not started" && req.body.status != "todo" && req.body.status != "in progress" && req.body.status != "done")
        return (false);
    return (true);
}

module.exports = async function(app, con) {
    app.get("/todos", glob.verifyToken, async (req, res) => {
        con.query(`SELECT * FROM todo;`, function (err2, rows) {
            if (err2) res.status(500).json({ msg: "Internal server error" });
            res.send(rows);
        });
    });

    app.post("/todos", glob.verifyToken, async (req, res) => {
        var user_id = 0;
        if (!error_handling_todo(req)) {
            res.status(400).json({ msg: "Bad parameter" });
            return (400);
        }
        if(!req.body.hasOwnProperty('user_id')) {
            user_id = get_id_with_token2(req, res);
        } else {
            user_id = req.body.user_id;
        }
        con.query(`INSERT INTO todo(title, description, due_time, user_id, status) VALUES("${req.body.title}", "${req.body.description}", "${req.body.due_time}", "${user_id}", "${req.body.status}")`, function (err, result) {
            if (err) {
                res.status(400).json({msg: "Not found"});
            } else {
                con.query(`SELECT * FROM todo ORDER BY id DESC LIMIT 1;`, function (err2, rows) {
                    if (err2) res.status(500).json({ msg: "Internal server error" });
                    res.status(201).json(rows[0]);
                });
            }
        });
    });
}
