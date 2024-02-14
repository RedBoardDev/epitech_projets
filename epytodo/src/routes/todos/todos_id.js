/*
** EPITECH PROJECT, 2021
** epytodo
** File description:
** todos_id.js
*/

var glob = require('../../config/global');

module.exports = async function(app, con) {
    app.get("/todos/:id", glob.verifyToken, async (req, res) => {
        if (!glob.is_num(req.params.id)) {
            res.status(400).json({ msg: "Bad parameter" });
            return;
        }
        con.query(`SELECT * FROM todo WHERE id = "${req.params.id}";`, function (err, rows) {
            if (err) res.status(500).json({ msg: "Internal server error" });
            if (rows[0])
                res.send(rows[0]);
            else
                res.status(200).json({ msg: "Not found"});
        });
    });

    app.put("/todos/:id", glob.verifyToken, async (req, res) => {
        if (!glob.is_num(req.params.id)) {
            res.status(400).json({ msg: "Bad parameter" });
            return;
        }
        var ret = false;
        if (req.body.hasOwnProperty('title')) {
            con.query(`UPDATE todo SET title = "${req.body.title}" WHERE id = "${req.params.id}";`, function (err, result) {
                if (err) {
                    try {
                        res.status(500).json({ msg: "Internal server error" });
                    } catch {}
                }
            });
            ret = true;
        }
        if (req.body.hasOwnProperty('description')) {
            con.query(`UPDATE todo SET description = "${req.body.description}" WHERE id = "${req.params.id}";`, function (err, result) {
                if (err) {
                    try {
                        res.status(500).json({ msg: "Internal server error" });
                    } catch {}
                }
            });
            ret = true;
        }
        if (req.body.hasOwnProperty('due_time')) {
            con.query(`UPDATE todo SET due_time = "${req.body.due_time}" WHERE id = "${req.params.id}";`, function (err, result) {
                if (err) {
                    try {
                        res.status(500).json({ msg: "Internal server error" });
                    } catch {}
                }
            });
            ret = true;
        }
        if (req.body.hasOwnProperty('user_id')) {
            con.query(`UPDATE todo SET user_id = "${req.body.user_id}" WHERE id = "${req.params.id}";`, function (err, result) {
                if (err) {
                    try {
                        res.status(500).json({ msg: "Internal server error" });
                    } catch {}
                }
            });
            ret = true;
        }
        if (req.body.hasOwnProperty('status')) {
            con.query(`UPDATE todo SET status = "${req.body.status}" WHERE id = "${req.params.id}";`, function (err, result) {
                if (err) {
                    try {
                        res.status(500).json({ msg: "Internal server error" });
                    } catch {}
                }
            });
            ret = true;
        }
        if (ret == true) {
            res.status(200).send(req.body);
        } else
            res.status(400).json({ msg: "Bad parameter" });
    });

    app.delete("/todos/:id", glob.verifyToken, async (req, res) => {
        if (!glob.is_num(req.params.id)) {
            res.status(400).json({ msg: "Bad parameter" });
            return;
        }
        con.query(`DELETE FROM todo WHERE id = "${req.params.id}";`, function (err, result) {
            if (err) res.status(500).json({ msg: "Internal server error" });
            if (result.affectedRows != 0)
                res.status(200).json({ msg: `Successfully deleted record number: ${req.params.id}` });
            else
                res.status(200).json({ msg: "Not found" });
        });
    });
}
