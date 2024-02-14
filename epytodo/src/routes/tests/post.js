/*
** EPITECH PROJECT, 2021
** epytodo
** File description:
** post.js
*/

module.exports = async function(app, con) {
    app.post("/POST", async (req, res) => {
        console.log("oui " + req.body['oui']);
        res.send(req.body);
    });
}
