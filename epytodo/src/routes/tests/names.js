/*
** EPITECH PROJECT, 2021
** epytodo
** File description:
** names.js
*/

module.exports = function(app) {
    app.get("/name", (req, res) => {
        res.send('Enter a name');
    });

    app.get("/name/text/:name", (req, res) => {
        let msg = "Hello " + req.params.name;
        res.send(msg);
    });

    app.get("/name/json/:name", (req, res) => {
        let msg = "Hello " + req.params.name;
        let myJson = {
            "msq": msg
        };
        res.send(myJson);
    });

    app.get("/name/html/:name", (req, res) => {
        let html = document.getElementById('oui');
        res.send(html);
    });
}
