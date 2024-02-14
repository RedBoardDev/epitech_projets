/*
** EPITECH PROJECT, 2021
** epytodo
** File description:
** get.js
*/

module.exports = async function(app, con) {
    app.get("/GET", async (req, res) => {
        con.query(`SELECT * FROM user;`, function (err2, rows) {
            if (err2) res.status(500).json({ msg: "Internal server error" });
            console.log("rows: " + rows);
            res.send(rows);
        });
    });
}
